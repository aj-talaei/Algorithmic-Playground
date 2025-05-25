// Source: https://leetcode.com/problems/flatten-nested-list-iterator/
// Description: Given a nested list of integers, implement an iterator that returns them in a flat sequence.
//              Each element may be an integer or another nested list.

#include <vector>
#include <stack>

using namespace std;

class NestedIterator {
public:
    NestedIterator(const vector<NestedInteger>& nestedList) {
        // Initialize stack with the outermost list
        stk.emplace(nestedList.begin(), nestedList.end());
    }

    // Returns the next integer in the flattened order.
    int next() {
        // hasNext() will have positioned us at an integer
        return (stk.top().first++)->getInteger();
    }

    // Returns true if there is a next integer available.
    bool hasNext() {
        while (!stk.empty()) {
            auto& [it, end] = stk.top();
            if (it == end) {
                // Finished this list
                stk.pop();
            } else if (it->isInteger()) {
                // Found an integer
                return true;
            } else {
                // Drill down into nested list
                const auto& lst = it->getList();
                ++it;
                stk.emplace(lst.begin(), lst.end());
            }
        }
        return false;
    }

private:
    // Stack of (current iterator, end iterator) pairs
    stack<pair<vector<NestedInteger>::const_iterator,
               vector<NestedInteger>::const_iterator>> stk;
};
