/*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* next;
     Node* random;
     
     Node(int _val) {
         val = _val;
         next = NULL;
         random = NULL;
     }
 };
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // 1) Interleave copied nodes:
        //    A→B→C  ⇒  A→A'→B→B'→C→C'
        for (Node* p = head; p; p = p->next->next) {
            Node* copy = new Node(p->val);
            copy->next = p->next;
            p->next = copy;
        }
        
        // 2) Assign random pointers:
        //    if original p.random points to R,
        //    then p.next.random (the copy's random) should point to R.next
        for (Node* p = head; p; p = p->next->next) {
            if (p->random)
                p->next->random = p->random->next;
        }
        
        // 3) Unweave the lists:
        //    restore original list and extract the copy list
        Node* newHead = head->next;
        for (Node* p = head; p; p = p->next) {
            Node* copy = p->next;
            p->next = copy->next;
            copy->next = copy->next ? copy->next->next : nullptr;
        }
        
        return newHead;
    }
};
