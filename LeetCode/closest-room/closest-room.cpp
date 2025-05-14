/*
 * Leetcode Problem: Closest Room
 *
 * You are given a list of rooms (room ID and size) and a list of queries (preferred ID and minimum size).
 * For each query, return the room ID such that:
 *   - The room's size is at least the minimum required size.
 *   - The absolute difference between the room ID and the preferred ID is minimized.
 *   - If there's a tie, choose the room with the smaller ID.
 * If no such room exists, return -1 for that query.
 *
 * Example:
 * Input: rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
 * Output: [3, -1, 3]
 *
 * Constraints:
 * - 1 <= rooms.length <= 10^5
 * - 1 <= queries.length <= 10^4
 * - 1 <= roomIdi, preferredj <= 10^7
 * - 1 <= sizei, minSizej <= 10^7
 */

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); ++i) {
            queries[i].push_back(i); // Append original index
        }

        auto sortBySizeDesc = [](const vector<int>& a, const vector<int>& b) {
            return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
        };

        sort(rooms.begin(), rooms.end(), sortBySizeDesc);
        sort(queries.begin(), queries.end(), sortBySizeDesc);

        vector<int> res(queries.size(), -1);
        set<int> validRoomIds;
        int j = 0;

        for (const auto& q : queries) {
            int preferred = q[0], minSize = q[1], idx = q[2];

            while (j < rooms.size() && rooms[j][1] >= minSize) {
                validRoomIds.insert(rooms[j][0]);
                ++j;
            }

            if (validRoomIds.empty()) continue;

            auto it = validRoomIds.lower_bound(preferred);
            int closest = -1;

            if (it != validRoomIds.end()) closest = *it;
            if (it != validRoomIds.begin()) {
                int left = *prev(it);
                if (closest == -1 || abs(left - preferred) <= abs(closest - preferred)) {
                    closest = left;
                }
            }

            res[idx] = closest;
        }

        return res;
    }
};
