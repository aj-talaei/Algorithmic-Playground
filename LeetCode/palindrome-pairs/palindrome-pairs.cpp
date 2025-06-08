// Source : https://leetcode.com/problems/palindrome-pairs/

class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordIndex;
        set<pair<int, int>> uniquePairs;

        // Map reversed words to their indices
        for (int i = 0; i < words.size(); ++i) {
            string reversed = words[i];
            reverse(reversed.begin(), reversed.end());
            wordIndex[reversed] = i;
        }

        // Handle empty string case
        if (wordIndex.count("")) {
            int emptyIdx = wordIndex[""];
            for (int i = 0; i < words.size(); ++i) {
                if (i != emptyIdx && isPalindrome(words[i], 0, words[i].size() - 1)) {
                    uniquePairs.emplace(i, emptyIdx);
                    uniquePairs.emplace(emptyIdx, i);
                }
            }
        }

        for (int i = 0; i < words.size(); ++i) {
            const string& word = words[i];
            int len = word.size();

            for (int j = 0; j <= len; ++j) {
                string left = word.substr(0, j);
                string right = word.substr(j);

                // Case 1: Right part is palindrome, find reversed left
                if (isPalindrome(word, j, len - 1)) {
                    auto it = wordIndex.find(left);
                    if (it != wordIndex.end() && it->second != i) {
                        uniquePairs.emplace(i, it->second);
                    }
                }

                // Case 2: Left part is palindrome, find reversed right
                if (j > 0 && isPalindrome(word, 0, j - 1)) {
                    auto it = wordIndex.find(right);
                    if (it != wordIndex.end() && it->second != i) {
                        uniquePairs.emplace(it->second, i);
                    }
                }
            }
        }

        vector<vector<int>> result;
        for (const auto& p : uniquePairs) {
            result.push_back({p.first, p.second});
        }

        return result;
    }
};
