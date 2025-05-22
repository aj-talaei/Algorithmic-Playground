// Source: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
// Description: Replace each "(key)" in a string with its value from a knowledge map or "?" if missing.

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string evaluate(const string& s, const vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        dict.reserve(knowledge.size());
        for (auto& kv : knowledge) {
            dict[kv[0]] = kv[1];
        }
        
        string result;
        result.reserve(s.size());
        string key;
        key.reserve(10);
        bool inBracket = false;
        
        for (char c : s) {
            if (c == '(') {
                inBracket = true;
                key.clear();
            } else if (c == ')') {
                inBracket = false;
                auto it = dict.find(key);
                result += (it != dict.end() ? it->second : "?");
            } else if (inBracket) {
                key += c;
            } else {
                result += c;
            }
        }
        
        return result;
    }
};
