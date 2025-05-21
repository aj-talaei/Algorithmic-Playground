// Source: https://leetcode.com/problems/design-authentication-manager/
// Description: Issue, renew, and count unexpired authentication tokens with fixed time-to-live.

#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class AuthenticationManager {
    int ttl;
    // Map tokenId -> expiry time
    unordered_map<string,int> expiry;
    // Queue of (tokenId, expiry) in the order they were generated or renewed
    queue<pair<string,int>> q;
public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}

    // Generate a new token that expires at currentTime + ttl
    void generate(const string& tokenId, int currentTime) {
        int exp = currentTime + ttl;
        expiry[tokenId] = exp;
        q.emplace(tokenId, exp);
    }

    // If token is unexpired, renew it to expire at currentTime + ttl
    void renew(const string& tokenId, int currentTime) {
        auto it = expiry.find(tokenId);
        if (it == expiry.end() || it->second <= currentTime) return;
        int exp = currentTime + ttl;
        it->second = exp;
        q.emplace(tokenId, exp);
    }

    // Remove all tokens that have expired by currentTime, then return count of remaining
    int countUnexpiredTokens(int currentTime) {
        while (!q.empty() && q.front().second <= currentTime) {
            auto &p = q.front();
            // Only erase if this queue entry matches the latest expiry in the map
            if (expiry[p.first] == p.second) {
                expiry.erase(p.first);
            }
            q.pop();
        }
        return expiry.size();
    }
};

