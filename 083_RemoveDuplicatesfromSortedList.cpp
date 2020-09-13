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
        ListNode *cur = head;
        
        while(cur != nullptr) {
            ListNode *tmp = cur->next;
            if(tmp && cur->val == tmp->val) {
                cur->next = tmp->next;
                delete tmp;
            }
            else
                cur = cur->next;
        }
        
        return head;
    }
};

// Runtime: 16 ms, faster than 35.67% of C++ online submissions for Remove Duplicates from Sorted List.
// Memory Usage: 11.8 MB, less than 5.28% of C++ online submissions for Remove Duplicates from Sorted List.