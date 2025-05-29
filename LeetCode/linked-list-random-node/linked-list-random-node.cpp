// Source : https://leetcode.com/problems/linked-list-random-node/

#include <cstdlib>
#include <ctime>

class Solution {
public:
    Solution(ListNode* head) : head(head), len(0) {
        for (ListNode* p = head; p != nullptr; p = p->next) ++len;
        std::srand(std::time(nullptr));
    }

    int getRandom() {
        int pos = std::rand() % len;
        ListNode* p = head;
        while (pos--) p = p->next;
        return p->val;
    }

private:
    ListNode* head;
    int len;
};
