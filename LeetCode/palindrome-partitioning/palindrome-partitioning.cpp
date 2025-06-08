// Source : https://leetcode.com/problems/palindrome-partitioning/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        dfs(s, 0, current, result);
        return result;
    }

private:
    void dfs(const string& s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, current, result);
                current.pop_back();  // Backtrack
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

// Optional helper for printing (for debugging or command-line use)
void printPartitions(const vector<vector<string>>& partitions) {
    for (const auto& partition : partitions) {
        cout << "{ ";
        for (const auto& word : partition) {
            cout << "\"" << word << "\", ";
        }
        cout << "}" << endl;
    }
}
