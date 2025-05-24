// Source: https://leetcode.com/problems/finding-the-users-active-minutes/
// Description: Given a log of [userID, minute] entries and an integer k, compute each user's
//              Unique Active Minutes (UAM)—the count of distinct minutes they were active.
//              Return a 1-indexed array `answer` of size k where answer[j] is the number of users
//              whose UAM equals j+1.

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        // Map each user to their set of unique active minutes
        unordered_map<int, unordered_set<int>> userMinutes;
        userMinutes.reserve(logs.size());
        
        for (auto& entry : logs) {
            int user = entry[0];
            int minute = entry[1];
            userMinutes[user].insert(minute);
        }
        
        // Build the answer array: count how many users have UAM = j for j=1..k
        vector<int> answer(k, 0);
        for (auto& [user, minutes] : userMinutes) {
            int uam = minutes.size();
            if (uam >= 1 && uam <= k) {
                answer[uam - 1]++;
            }
        }
        
        return answer;
    }
};

