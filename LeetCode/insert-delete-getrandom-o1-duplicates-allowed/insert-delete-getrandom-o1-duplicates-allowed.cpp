// Problem: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
// Design a data structure that allows insertion, deletion, and random access of elements in O(1) time on average.
// Duplicates are allowed. getRandom() returns elements proportionally to their frequency.

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
using namespace std;

class RandomizedCollection {
public:
    RandomizedCollection() {
        srand(time(nullptr));
    }

    bool insert(int val) {
        data.push_back(val);
        indices[val].insert(data.size() - 1);
        return indices[val].size() == 1;
    }

    bool remove(int val) {
        if (!indices.count(val)) return false;

        // Get an index of the value to remove
        int idxToRemove = *indices[val].begin();
        int lastVal = data.back();

        // Overwrite the value at idxToRemove with the last element
        data[idxToRemove] = lastVal;

        // Update sets BEFORE erasing anything
        indices[val].erase(idxToRemove);
        indices[lastVal].erase(data.size() - 1);
        if (idxToRemove < data.size() - 1) {
            indices[lastVal].insert(idxToRemove);
        }

        // Clean up if no more entries for val
        if (indices[val].empty()) {
            indices.erase(val);
        }

        data.pop_back();
        return true;
    }

    int getRandom() {
        return data[rand() % data.size()];
    }

private:
    vector<int> data;
    unordered_map<int, unordered_set<int>> indices;
};
