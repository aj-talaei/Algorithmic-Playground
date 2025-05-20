// File: course_schedule.cpp
// Source: https://leetcode.com/problems/course-schedule/
// Description: Determine if you can finish all courses given their prerequisites, i.e. check for cycles in the directed graph.

#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }
        // 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0 && hasCycle(i, graph, state))
                return false;
        }
        return true;
    }

private:
    bool hasCycle(int u, vector<vector<int>>& graph, vector<int>& state) {
        state[u] = 1;  // mark as visiting
        for (int v : graph[u]) {
            if (state[v] == 1) 
                return true;                // found a back edge -> cycle
            if (state[v] == 0 && hasCycle(v, graph, state))
                return true;
        }
        state[u] = 2;  // mark as visited
        return false;
    }
};
