// Source : https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        vector<string> itinerary;

        // Build the graph: use multiset to maintain lexical order
        for (const auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        // Perform DFS traversal
        function<void(const string&)> dfs = [&](const string& airport) {
            auto& destinations = graph[airport];
            while (!destinations.empty()) {
                string next = *destinations.begin();
                destinations.erase(destinations.begin());
                dfs(next);
            }
            itinerary.push_back(airport);
        };

        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
