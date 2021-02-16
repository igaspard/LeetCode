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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        ListNode *cur = head, *pre = dummy, *next = nullptr;
        while(cur != nullptr) {
            next = cur->next;
            if (cur->val == val) {
                pre->next = next;
                delete cur;
            } else {
                pre = cur;    
            }
            cur = next;
        }
     
        ListNode *tmp = dummy->next;
        delete dummy;
        return tmp;
    }
};

// Use sentinel node point to head make linked list to be never empty and never headless and hence simplify insert and delete.

// Runtime: 36 ms, faster than 34.39% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 15.5 MB, less than 6.45% of C++ online submissions for Remove Linked List Elements.