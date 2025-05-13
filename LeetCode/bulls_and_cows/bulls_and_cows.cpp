// Problem: Bulls and Cows
// Source: https://leetcode.com/problems/bulls-and-cows/
//
// You are given two strings: `secret` and `guess`. Each contains only digits and has the same length.
// You need to return a hint string that tells how many digits are correct in both value and position ("bulls")
// and how many digits are correct in value but not in position ("cows").
// Format the output as "xAyB" where x is the number of bulls and y is the number of cows.

class Solution {
public:
    string getHint(string secret, string guess) {
        const int digits = 10;
        int secret_count[digits] = {0};
        int bull = 0, cow = 0;

        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bull++;
            } else {
                secret_count[secret[i] - '0']++;
            }
        }

        for (int i = 0; i < guess.size(); ++i) {
            if (secret[i] != guess[i] && secret_count[guess[i] - '0']-- > 0) {
                cow++;
            }
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
