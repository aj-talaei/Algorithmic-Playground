// source: https://leetcode.com/problems/minimum-number-of-people-to-teach/

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> userLangs(m);
        for (int i = 0; i < m; ++i) {
            for (int lang : languages[i]) {
                userLangs[i].insert(lang);
            }
        }

        unordered_set<int> needTeach;
        vector<pair<int, int>> cannotCommunicate;

        // Identify pairs who cannot communicate
        for (const auto& f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;
            bool shared = false;
            for (int lang : userLangs[u]) {
                if (userLangs[v].count(lang)) {
                    shared = true;
                    break;
                }
            }
            if (!shared) {
                cannotCommunicate.emplace_back(u, v);
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }

        // Count the best language to teach
        unordered_map<int, int> langCount;
        for (int user : needTeach) {
            for (int lang : userLangs[user]) {
                langCount[lang]++;
            }
        }

        int maxKnown = 0;
        for (const auto& [lang, count] : langCount) {
            maxKnown = max(maxKnown, count);
        }

        return needTeach.size() - maxKnown;
    }
};
