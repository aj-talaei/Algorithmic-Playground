// source: https://leetcode.com/problems/repeated-dna-sequences
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int MAX_LEN = 10;
        if (s.size() < MAX_LEN) return {};

        unordered_map<int, int> count;
        vector<string> result;

        int hash = 0;
        unordered_map<char, int> map = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        for (int i = 0; i < MAX_LEN; ++i) {
            hash = (hash << 2) | map[s[i]];
        }
        count[hash] = 1;

        int mask = (1 << (2 * MAX_LEN)) - 1;
        for (int i = MAX_LEN; i < s.size(); ++i) {
            hash = ((hash << 2) & mask) | map[s[i]];
            if (++count[hash] == 2) {
                result.push_back(s.substr(i - MAX_LEN + 1, MAX_LEN));
            }
        }

        return result;
    }
};
