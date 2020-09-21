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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *cur = head, *pre = nullptr;
        for (int i = 0; cur != nullptr && i < m - 1; ++i) {
            pre = cur;
            cur = cur->next;
        }
        ListNode *pminus1 = pre;
        ListNode *pNode = cur;
        // Reverse m ~ n

        ListNode *next = nullptr;
        for (int i = m; cur != nullptr && i < n + 1; ++i) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // Connect m-1 & n+1
        if (pminus1 != nullptr)
            pminus1->next = pre;
        else
            head = pre;
        pNode->next = cur;

        return head;
    }
};

// Runtime: 4 ms, faster than 61.41% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 7.7 MB, less than 10.87% of C++ online submissions for Reverse Linked List II.