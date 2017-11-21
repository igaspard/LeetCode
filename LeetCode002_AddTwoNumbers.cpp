/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode *prev = NULL, *head = NULL;
        while(l1 && l2) {
            int sum = l1->val + l2->val + c;
            if(sum >= 10) {
                c = 1;
                sum %= 10;
            }
            else
                c = 0;
            ListNode *out = new ListNode(sum);
            if(prev)
                prev->next = out;
            else
                head = out;
            prev = out;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int sum = l1->val + c;
            if(sum >= 10) {
                c = 1;
                sum %= 10;
            }
            else
                c = 0;
            ListNode *out = new ListNode(sum);
            if(prev)
                prev->next = out;
            prev = out;
            l1 = l1->next;
        }
        while(l2) {
            int sum = l2->val + c;
            if(sum >= 10) {
                c = 1;
                sum %= 10;
            }
            else
                c = 0;
            ListNode *out = new ListNode(sum);
            if(prev)
                prev->next = out;
            prev = out;
            l2 = l2->next;
        }
        if(c) {
            ListNode *out = new ListNode(c);
            prev->next = out;
        }
        return head;
    }
};

// Test cases
// [5], [5]     -> [0, 1]
// [1], [9, 9]  -> [0, 0, 1]
// [0], [1, 8]  -> [1, 8]
// [1], [9]     -> [0, 1]
