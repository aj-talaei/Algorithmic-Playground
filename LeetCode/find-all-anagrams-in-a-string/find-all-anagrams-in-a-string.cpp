// Source: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Description: Given a string s and a non-empty string p, find all start indices of p's anagrams in s.
//               Strings consist of lowercase English letters only.

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> ans;
        if (n < m) return ans;

        // count[i] will track window_count[i] - p_count[i]
        int count[26] = {0};
        for (int i = 0; i < m; i++) {
            count[s[i] - 'a']++;
            count[p[i] - 'a']--;
        }
        
        // zeros = number of characters with count[c] == 0
        int zeros = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) zeros++;
        }
        if (zeros == 26) ans.push_back(0);

        // slide the window
        for (int i = m; i < n; i++) {
            int in  = s[i]     - 'a';
            int out = s[i - m] - 'a';
            
            // add s[i]
            if (count[in] == 0) zeros--;
            count[in]++;
            if (count[in] == 0) zeros++;

            // remove s[i-m]
            if (count[out] == 0) zeros--;
            count[out]--;
            if (count[out] == 0) zeros++;

            if (zeros == 26) {
                ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};
