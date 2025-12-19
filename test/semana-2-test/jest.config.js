module.exports = {
  preset: 'jest-preset-angular',
  setupFilesAfterEnv: ['<rootDir>/setup-jest.ts'],
  testEnvironment: "jsdom",
  transform: {
    ...tsJestTransformCfg,
  },
  moduleFileExtensions: ['ts', 'html', 'js', 'json', 'mjs'],
};
