// Problem: https://leetcode.com/problems/insert-delete-getrandom-o1/
// Design a data structure that supports insert(val), remove(val), and getRandom() in average O(1) time.
// - insert(val): Inserts val if not already present.
// - remove(val): Removes val if present.
// - getRandom(): Returns a random element from the set with equal probability.

#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(nullptr));
    }

    bool insert(int val) {
        if (valIndex.count(val)) return false;
        data.push_back(val);
        valIndex[val] = data.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!valIndex.count(val)) return false;
        int idx = valIndex[val];
        int last = data.back();

        data[idx] = last;
        valIndex[last] = idx;

        data.pop_back();
        valIndex.erase(val);
        return true;
    }

    int getRandom() {
        return data[rand() % data.size()];
    }

private:
    unordered_map<int, int> valIndex;  // maps value to its index in data
    vector<int> data;
};
