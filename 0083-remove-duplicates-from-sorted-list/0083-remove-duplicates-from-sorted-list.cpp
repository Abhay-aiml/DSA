/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;  // empty list, nothing to do

        ListNode* prev = head;       // pointer 1: last "confirmed unique" node
        ListNode* curr = head->next; // pointer 2: scout, checks ahead

        while (curr != nullptr) {
            if (curr->val == prev->val) {
                // duplicate found, skip it
                curr = curr->next;
            } else {
                // new unique value, link prev to it and advance both
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }

        prev->next = nullptr;  // cut off any leftover duplicate tail
        return head;
    }
};
        
    
