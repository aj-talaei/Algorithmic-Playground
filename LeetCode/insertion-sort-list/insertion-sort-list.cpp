// Problem: Insertion Sort List
// URL: https://leetcode.com/problems/insertion-sort-list/
// Sort a singly-linked list using insertion sort.

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* cur = head;
        
        while (cur) {
            ListNode* next = cur->next;
            ListNode* prev = &dummy;
            
            // Find insertion point
            while (prev->next && prev->next->val < cur->val) {
                prev = prev->next;
            }
            
            // Insert cur between prev and prev->next
            cur->next = prev->next;
            prev->next = cur;
            
            cur = next;
        }
        
        return dummy.next;
    }
};
