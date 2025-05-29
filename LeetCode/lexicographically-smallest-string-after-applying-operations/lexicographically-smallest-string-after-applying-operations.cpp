// Source : https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        string result = s;
        dfs(s, a, b, visited, result);
        return result;
    }

private:
    void dfs(string s, int a, int b, unordered_set<string>& visited, string& result) {
        if (visited.count(s)) return;
        visited.insert(s);
        result = min(result, s);

        string rotated = rotate(s, b);
        dfs(rotated, a, b, visited, result);

        string added = add(s, a);
        dfs(added, a, b, visited, result);
    }

    static string rotate(const string& s, int b) {
        return s.substr(b) + s.substr(0, b);
    }

    static string add(const string& s, int a) {
        string res = s;
        for (int i = 1; i < res.size(); i += 2) {
            res[i] = (res[i] - '0' + a) % 10 + '0';
        }
        return res;
    }
};
