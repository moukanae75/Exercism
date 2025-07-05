import maintainers from './maintainers.mjs';

export default [
  ...maintainers,
  {
    ignores: [
      '.appends/**/*',
      '.github/**/*',
      '.vscode/**/*',
      '.yarn/**/*',
      '.pnp.*',
    ],
  },
];
