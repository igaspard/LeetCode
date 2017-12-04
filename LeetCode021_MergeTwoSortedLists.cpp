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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *prev;
        bool bHead = true;
        while(l1 && l2) {
            ListNode *out = new ListNode(0);
            if(l1->val <= l2->val) {
                out->val = l1->val;
                l1 = l1->next;
            }
            else {
                out->val = l2->val;
                l2 = l2->next;
            }

            if(bHead) {
                head = out;
                prev = head;
                bHead = false;
            }
            else {
                prev->next = out;
                prev = out;
            }
        }

        while(l1) {
            ListNode *out = new ListNode(l1->val);
            if(bHead) {
                head = out;
                prev = head;
                bHead = false;
            }
            else {
                prev->next = out;
                prev = out;
            }
            l1 = l1->next;
        }

        while(l2) {
            ListNode *out = new ListNode(l2->val);
            if(bHead) {
                head = out;
                prev = head;
                bHead = false;
            }
            else {
                prev->next = out;
                prev = out;
            }
            l2 = l2->next;
        }

        return head;
    }
};
