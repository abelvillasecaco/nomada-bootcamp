import { toUpper, reverse, isPalindrome } from "./stringUtils";

describe('stringUtils module', () => {

  describe('toUpper()', () => {
    it('converts "hola" to "HOLA"', () => {
      expect(toUpper('hola')).toBe('HOLA');
    });
  });

  describe('reverse()', () => {
    it('reverses "javascript" to "tpircsavaj"', () => {
      expect(reverse('javascript')).toBe('tpircsavaj');
    });
  });

  describe('isPalindrome()', () => {
    it('detects a palidrome phrase with spaces', () => {
      expect(isPalindrome('reconocer')).toBe(true);
    });

    it('return false for non-palidrome phrases', () => {
      expect(isPalindrome('Hola mundo')).toBe(false);
    });
  });

});
