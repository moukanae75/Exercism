// @ts-check

import fs from 'fs';

import eslint from '@eslint/js';
import tsEslint from 'typescript-eslint';
import jestPlugin from 'eslint-plugin-jest';
import stylisticTs from '@stylistic/eslint-plugin-ts';
import prettierConfig from 'eslint-config-prettier';

import globals from 'globals';

const pkg = JSON.parse(
  fs.readFileSync(new URL('./package.json', import.meta.url), 'utf8'),
);

/** @type {import('eslint').ESLint.Plugin} */
const plugin = {
  meta: {
    name: pkg.name + '/maintainers',
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
    extends: [eslint.configs.recommended, ...tsEslint.configs.recommended],
    rules: {
      // @typescript-eslint rules
      '@typescript-eslint/explicit-function-return-type': [
        'warn',
        {
          allowExpressions: false,
          allowTypedFunctionExpressions: true,
          allowHigherOrderFunctions: true,
        },
      ],
      '@typescript-eslint/explicit-member-accessibility': [
        'warn',
        {
          accessibility: 'no-public',
          overrides: {
            accessors: 'explicit',
            constructors: 'no-public',
            methods: 'explicit',
            properties: 'explicit',
            parameterProperties: 'off',
          },
        },
      ],
      '@typescript-eslint/no-inferrable-types': [
        'error',
        {
          ignoreParameters: true,
        },
      ],
      '@typescript-eslint/no-non-null-assertion': 'off',
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
      'no-use-before-define': 'off',
      '@typescript-eslint/no-use-before-define': [
        'error',
        {
          functions: false,
          typedefs: false,
        },
      ],
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

      // disable the rule for all* (js) files (see overrides for enabling it)
      '@typescript-eslint/explicit-module-boundary-types': 'off',

      // eslint rules
      'array-callback-return': ['error', { checkForEach: true }],
      'default-param-last': 'error',
      eqeqeq: ['error', 'smart'],
      'linebreak-style': 'off',
      'no-eval': ['error', { allowIndirect: true }],
      'no-extend-native': 'error',
      'no-implicit-coercion': 'error',
      'no-promise-executor-return': 'error',
      'no-unreachable-loop': 'error',
      'no-unsafe-optional-chaining': 'error',
      'require-atomic-updates': 'error',
    },
  },
  {
    files: ['**.ts', '**.tsx'],
    extends: [...tsEslint.configs.recommendedTypeCheckedOnly],
    rules: {
      // Enable boundary checks on TS files
      '@typescript-eslint/explicit-module-boundary-types': 'error',

      // stylistic choice
      '@stylistic/ts/semi': ['error', 'never'],
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
    languageOptions: {
      globals: {
        // Don't make jest globals available! These should not be available
        // but imported from @jest/globals.
        //
        // ...globals.jest,
      },
    },
  },

  // https://github.com/import-js/eslint-plugin-import/pull/3018
  // missing: import/* plugins

  prettierConfig,
);
