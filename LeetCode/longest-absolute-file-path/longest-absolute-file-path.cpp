// Source : https://leetcode.com/problems/longest-absolute-file-path/

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthLongestPath(const std::string& input) {
        std::istringstream ss(input);
        std::string line;
        std::vector<int> pathLenAtDepth(1, 0);  // pathLenAtDepth[i] = total path length at depth i
        int maxLen = 0;

        while (std::getline(ss, line)) {
            int depth = 0;
            while (depth < line.size() && line[depth] == '\t') ++depth;

            std::string name = line.substr(depth);
            bool isFile = name.find('.') != std::string::npos;

            if (pathLenAtDepth.size() <= depth + 1)
                pathLenAtDepth.resize(depth + 2);

            if (isFile) {
                int totalLen = pathLenAtDepth[depth] + name.size();
                maxLen = std::max(maxLen, totalLen);
            } else {
                pathLenAtDepth[depth + 1] = pathLenAtDepth[depth] + name.size() + 1;  // +1 for '/'
            }
        }

        return maxLen;
    }
};
