// Source: https://leetcode.com/problems/find-the-winner-of-an-array-game/
// Description: Given a distinct-integer array `arr` and an integer `k`, play rounds comparing
//              the first two elements: the larger wins and stays at front, the smaller goes to back.
//              The first element to win `k` consecutive rounds is the overall winner. Guaranteed to exist.

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0];
        int win_count = 0;
        int n = arr.size();
        
        for (int i = 1; i < n; ++i) {
            if (winner < arr[i]) {
                // new challenger wins
                winner = arr[i];
                win_count = 1;
            } else {
                // current winner wins again
                ++win_count;
            }
            if (win_count == k) {
                return winner;
            }
        }
        // If k ≥ n, eventual winner is the maximum element
        return *max_element(arr.begin(), arr.end());
    }
};
