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
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // when the list is odd, need to move slow one step
        if (fast != nullptr) slow = slow->next;

        ListNode *left = head;
        ListNode *right = reverse(slow);
        while (right != nullptr) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *pre = nullptr, *cur = head;

        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

// fast & slow pointers, use it to find mid point and reverse right half of linked list, then compare first half with second
// Time complexity: O(N)
// Slow complexity: O(1)
// Runtime: 188 ms, faster than 74.31% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 114.1 MB, less than 76.12% of C++ online submissions for Palindrome Linked List.
