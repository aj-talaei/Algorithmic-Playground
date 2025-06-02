// Source: https://leetcode.com/problems/merge-k-sorted-lists/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Min-heap comparator
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for (auto node : lists) {
            if (node) minHeap.push(node);
        }

        ListNode dummy(0), *tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            tail->next = smallest;
            tail = tail->next;
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};
