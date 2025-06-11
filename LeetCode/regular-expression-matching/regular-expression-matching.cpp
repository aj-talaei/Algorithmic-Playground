// source: https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        return matchHelper(0, 0, s, p);
    }

private:
    unordered_map<string, bool> memo;

    bool matchHelper(int i, int j, const string& s, const string& p) {
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];

        if (j == p.size()) return memo[key] = (i == s.size());

        bool first_match = (i < s.size()) && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Two options: skip the '*', or use it if first matches
            bool result = matchHelper(i, j + 2, s, p) || (first_match && matchHelper(i + 1, j, s, p));
            return memo[key] = result;
        } else {
            return memo[key] = first_match && matchHelper(i + 1, j + 1, s, p);
        }
    }
};
