// @ts-check

import fs from 'fs';

import eslint from '@eslint/js';
import tsEslint from 'typescript-eslint';
import jestPlugin from 'eslint-plugin-jest';
import stylisticTs from '@stylistic/eslint-plugin-ts';

import globals from 'globals';

const pkg = JSON.parse(
  fs.readFileSync(new URL('./package.json', import.meta.url), 'utf8'),
);

/** @type {import('eslint').ESLint.Plugin} */
const plugin = {
  meta: {
    name: pkg.name,
    version: pkg.version,
  },
};

export default tsEslint.config(
  {
    plugins: {
      '@typescript-eslint': tsEslint.plugin,
      '@stylistic/ts': stylisticTs,
      jest: jestPlugin,
      // @ts-expect-error we know this is set from the contents above, but the type makes it optional
      [plugin.meta.name]: plugin,
    },
    languageOptions: {
      parser: tsEslint.parser,
      parserOptions: {
        project: true,
      },
      globals: {
        ...globals.node,
      },
    },
    extends: [
      eslint.configs.recommended,
      ...tsEslint.configs.recommendedTypeChecked,
    ],
    rules: {
      // @typescript-eslint rules to prevent bugs
      '@typescript-eslint/explicit-function-return-type': [
        'warn',
        {
          allowExpressions: false,
          allowTypedFunctionExpressions: true,
          allowHigherOrderFunctions: true,
        },
      ],

      '@typescript-eslint/no-inferrable-types': [
        'error',
        {
          ignoreParameters: true,
        },
      ],

      'no-shadow': 'off',
      '@typescript-eslint/no-shadow': 'error',

      // @typescript-eslint rules: code style not forced upon the student
      '@typescript-eslint/array-type': 'off',
      '@typescript-eslint/explicit-member-accessibility': 'off',
      '@typescript-eslint/indent': 'off',
      '@typescript-eslint/member-delimiter-style': 'off',
      '@typescript-eslint/no-non-null-assertion': 'off',

      // @typescript-eslint rules: exceptions.
      // Only disallow readonly without an access modifier
      '@typescript-eslint/parameter-properties': [
        'warn',
        {
          allow: [
            'private',
            'protected',
            'public',
            'private readonly',
            'protected readonly',
            'public readonly',
          ],
        },
      ],

      // Prevent bugs, not styling
      '@typescript-eslint/no-unused-vars': [
        'error',
        {
          args: 'all',
          argsIgnorePattern: '^_',
          caughtErrors: 'all',
          caughtErrorsIgnorePattern: '^_',
          destructuredArrayIgnorePattern: '^_',
          varsIgnorePattern: '^_',
          ignoreRestSiblings: true,
        },
      ],
      '@typescript-eslint/no-use-before-define': [
        'error',
        {
          functions: false,
          typedefs: false,
        },
      ],

      // eslint rules
      'array-callback-return': ['warn', { checkForEach: false }],
      'default-param-last': 'error',
      eqeqeq: ['warn', 'smart'],
      'linebreak-style': 'off',
      'no-eval': ['error', { allowIndirect: true }],
      'no-extend-native': 'warn',
      'no-implicit-coercion': 'warn',
      'no-promise-executor-return': 'warn',
      'no-unreachable-loop': 'warn',
      'no-unsafe-optional-chaining': 'error',
      'require-atomic-updates': 'warn',
    },
  },
  {
    // disable type-aware linting on JS files
    files: ['**/*.js', '**/*.cjs', '**/*.mjs'],
    ...tsEslint.configs.disableTypeChecked,
  },
  {
    // enable jest rules on test files
    files: [
      'test/**',
      '**/*.spec.js*',
      '**/*.test.js*',
      '**/*.spec.ts*',
      '**/*.test.ts*',
    ],
    ...jestPlugin.configs['flat/recommended'],
    rules: {
      ...jestPlugin.configs['flat/recommended'].rules,
      'jest/no-disabled-tests': 'off',
      'jest/no-test-prefixes': 'off',
    },
  },
);
