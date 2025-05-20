// Source: https://leetcode.com/problems/course-schedule-ii/
// Description: Return one possible order to finish all courses given their prerequisites (topological sort).

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            ++indegree[pre[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) 
                q.push(i);
        }
        
        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : graph[u]) {
                if (--indegree[v] == 0) 
                    q.push(v);
            }
        }
        
        return (order.size() == numCourses ? order : vector<int>{});
    }
};
