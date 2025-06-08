// Source : https://oj.leetcode.com/problems/partition-list/

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeHead(0), afterHead(0);
        ListNode* before = &beforeHead;
        ListNode* after = &afterHead;

        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        after->next = nullptr; // terminate after list
        before->next = afterHead.next; // connect two lists

        return beforeHead.next;
    }
};

// Utility: create a list from array
ListNode* createList(const int* arr, int n) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int i = 0; i < n; ++i) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return dummy.next;
}

// Utility: print a list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}