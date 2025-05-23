// Source: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
// Description: Filter a list of restaurants by vegan‐friendly flag, maximum price, and maximum distance,
// then return their IDs sorted by descending rating (and by descending ID when ratings tie).

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                  int veganFriendly,
                                  int maxPrice,
                                  int maxDistance) {
        vector<vector<int>> filtered;
        filtered.reserve(restaurants.size());
        
        // Apply filters
        for (auto& r : restaurants) {
            int id        = r[0];
            int rating    = r[1];
            int veganFlag = r[2];
            int price     = r[3];
            int dist      = r[4];
            
            if (veganFriendly && veganFlag == 0) continue;
            if (price > maxPrice)    continue;
            if (dist  > maxDistance) continue;
            
            filtered.push_back(r);
        }
        
        // Sort by rating descending, then ID descending
        sort(filtered.begin(), filtered.end(),
             [](auto &a, auto &b) {
                 if (a[1] != b[1]) 
                     return a[1] > b[1];
                 return a[0] > b[0];
             });
        
        // Extract IDs
        vector<int> result;
        result.reserve(filtered.size());
        for (auto& r : filtered) {
            result.push_back(r[0]);
        }
        return result;
    }
};
