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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while(l1 && l2) {
            if (l1->val > l2->val) 
                swap(l1, l2);
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

// Runtime: 12 ms, faster than 40.90% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 15.1 MB, less than 5.03% of C++ online submissions for Merge Two Sorted Lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // w/o use new node
 class NewSolution {
 public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode *head = NULL, *prev = NULL;

         if(l1==NULL)
             return l2;
         if(l2==NULL)
             return l1;

         if(l1->val > l2->val) {
             head = l2;
             prev = head;
             l2 = l2->next;
         }
         else {
             head = l1;
             prev = head;
             l1 = l1->next;
         }

         while(l1 && l2) {
             if(l1->val > l2->val) {
                 prev->next = l2;
                 prev = l2;
                 l2 = l2->next;
             }
             else {
                 prev->next = l1;
                 prev = l1;
                 l1 = l1->next;
             }
         }

         if(l1==NULL)
             prev->next = l2;
         if(l2==NULL)
             prev->next = l1;

         return head;
     }
 };


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
