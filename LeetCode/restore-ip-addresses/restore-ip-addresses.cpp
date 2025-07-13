// source: https://leetcode.com/problems/restore-ip-addresses

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        dfs(s, 0, 0, ip, result);
        return result;
    }

private:
    void dfs(const string& s, int start, int partNum, string ip, vector<string>& result) {
        if (partNum == 4 && start == s.length()) {
            ip.pop_back(); // remove the trailing '.'
            result.push_back(ip);
            return;
        }

        if (partNum >= 4) return;

        for (int len = 1; len <= 3 && start + len <= s.length(); ++len) {
            string part = s.substr(start, len);
            if ((part[0] == '0' && part.length() > 1) || stoi(part) > 255) continue;
            dfs(s, start + len, partNum + 1, ip + part + '.', result);
        }
    }
};
