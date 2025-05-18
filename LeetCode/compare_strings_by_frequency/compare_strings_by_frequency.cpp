
// Problem: Compare Strings by Frequency of the Smallest Character
// Link: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
//
// Description:
// Define f(s) as the frequency of the smallest character in a non-empty string s.
// Given string arrays `queries` and `words`, return an integer array `answer` where
// `answer[i]` is the number of words W in `words` such that f(queries[i]) < f(W).
//
// Constraints:
// - 1 <= queries.length, words.length <= 2000
// - 1 <= queries[i].length, words[i].length <= 10
// - queries[i][j], words[i][j] are lowercase English letters.

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries,
                                      vector<string>& words) {
        // Precompute f(w) for each word and count frequencies (max f <= 10)
        int freqCount[11] = {0};
        for (auto& w : words) {
            ++freqCount[f(w)];
        }
        // Build suffix sums: suffix[i] = count of words with f >= i
        for (int i = 9; i >= 1; --i) {
            freqCount[i] += freqCount[i + 1];
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        for (auto& q : queries) {
            int fq = f(q);
            // We want count of words with f(w) > fq, that is freqCount[fq + 1]
            answer.push_back(fq < 10 ? freqCount[fq + 1] : 0);
        }
        return answer;
    }

private:
    // Compute f(s): frequency of the smallest character in s
    int f(const string& s) {
        char smallest = 'z';
        int count = 0;
        for (char c : s) {
            if (c < smallest) {
                smallest = c;
                count = 1;
            } else if (c == smallest) {
                ++count;
            }
        }
        return count;
    }
};
