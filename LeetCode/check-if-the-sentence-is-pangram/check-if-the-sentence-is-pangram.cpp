/*
 * Leetcode Problem: Check if the Sentence Is Pangram
 *
 * A pangram is a sentence where every letter of the English alphabet appears at least once.
 * Given a string `sentence` containing only lowercase English letters, return true if it is a pangram.
 *
 * Example:
 * Input: sentence = "thequickbrownfoxjumpsoverthelazydog" → Output: true
 * Input: sentence = "leetcode" → Output: false
 */

class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool stat[26] = {false};
        for (char c : sentence) {
            stat[c - 'a'] = true;
        }
        for (bool seen : stat) {
            if (!seen) return false;
        }
        return true;
    }
};
