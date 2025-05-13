/*
 * Leetcode Problem: Check if Word Equals Summation of Two Words
 *
 * Each lowercase letter from 'a' to 'j' has a value from 0 to 9 respectively. The numerical value
 * of a word is formed by concatenating the values of its letters and converting the result to an integer.
 *
 * Given three strings `firstWord`, `secondWord`, and `targetWord`, return true if the sum of the numerical
 * values of the first two words equals the numerical value of the target word.
 *
 * Example:
 * Input: firstWord = "acb", secondWord = "cba", targetWord = "cdb"
 * Output: true
 * Explanation: "acb" = 021 = 21, "cba" = 210, "cdb" = 231 → 21 + 210 == 231
 */

class Solution {
public:
    int strToInt(string& str) {
        int n = 0;
        for (char c : str) {
            n = n * 10 + (c - 'a');
        }
        return n;
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return strToInt(firstWord) + strToInt(secondWord) == strToInt(targetWord);
    }
};
