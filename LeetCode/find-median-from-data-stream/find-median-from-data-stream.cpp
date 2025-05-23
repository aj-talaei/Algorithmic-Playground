// Source: https://leetcode.com/problems/find-median-from-data-stream/
// Description: Maintain two multisets (heaps) to dynamically compute the median of a data stream in O(log n) per insertion.

#include <set>
using namespace std;

class MedianFinder {
private:
    // 'lower' holds the smaller half of the numbers (max at rbegin)
    // 'upper' holds the larger half of the numbers (min at begin)
    multiset<int> lower, upper;

public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (lower.empty() || num <= *lower.rbegin())
            lower.insert(num);
        else
            upper.insert(num);

        // Rebalance so that |lower| == |upper| or |lower| == |upper| + 1
        if (lower.size() > upper.size() + 1) {
            auto it = prev(lower.end());
            upper.insert(*it);
            lower.erase(it);
        } else if (lower.size() < upper.size()) {
            auto it = upper.begin();
            lower.insert(*it);
            upper.erase(it);
        }
    }

    // Returns the median of current data stream.
    double findMedian() {
        if (lower.size() > upper.size())
            return *lower.rbegin();
        return (static_cast<double>(*lower.rbegin()) + *upper.begin()) / 2.0;
    }
};
// File: find_median_from_data_stream.cpp
// Source: https://leetcode.com/problems/find-median-from-data-stream/
// Description: Maintain two multisets (heaps) to dynamically compute the median of a data stream in O(log n) per insertion.

#include <set>
using namespace std;

class MedianFinder {
private:
    // 'lower' holds the smaller half of the numbers (max at rbegin)
    // 'upper' holds the larger half of the numbers (min at begin)
    multiset<int> lower, upper;

public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (lower.empty() || num <= *lower.rbegin())
            lower.insert(num);
        else
            upper.insert(num);

        // Rebalance so that |lower| == |upper| or |lower| == |upper| + 1
        if (lower.size() > upper.size() + 1) {
            auto it = prev(lower.end());
            upper.insert(*it);
            lower.erase(it);
        } else if (lower.size() < upper.size()) {
            auto it = upper.begin();
            lower.insert(*it);
            upper.erase(it);
        }
    }

    // Returns the median of current data stream.
    double findMedian() {
        if (lower.size() > upper.size())
            return *lower.rbegin();
        return (static_cast<double>(*lower.rbegin()) + *upper.begin()) / 2.0;
    }
};
