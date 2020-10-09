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
        if (head == nullptr) return true;
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second_half = Reverse(slow);
        ListNode *backup = second_half;
        ListNode *first_half = head;

        while (second_half != nullptr && first_half != nullptr) {
            if (first_half->val != second_half->val) break;
            first_half = first_half->next;
            second_half = second_half->next;
        }

        Reverse(backup);
        if (first_half == nullptr || second_half == nullptr)
            return true;
        else
            return false;
    }

    ListNode *Reverse(ListNode *head) {
        ListNode *cur = head, *pre = nullptr, *next = nullptr;

        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

// Fast & slow algorithms, slow as mid and then reverse second half and compare with first one
// Time complexity: O(N)
// Space complexity: O(1)
// Runtime: 24 ms, faster than 92.43% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 14.5 MB, less than 12.30% of C++ online submissions for Palindrome Linked List.

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
        if (head == nullptr) return true;
        ListNode *slow = head, *fast = head;
        stack<ListNode *> s;
        while (fast != nullptr && fast->next != nullptr) {
            s.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast == nullptr) {
            ListNode *mid = s.top();
            s.pop();
            if (slow->val != mid->val) return false;
        }

        while (slow->next != nullptr) {
            ListNode *tmp = s.top();
            s.pop();
            slow = slow->next;
            if (slow->val != tmp->val) return false;
        }

        return true;
    }
};

// Fast & slow algorithms
// Time complexity: O(N)
// Space complexity: O(N)
// Runtime: 24 ms, faster than 92.43% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 14.7 MB, less than 12.30% of C++ online submissions for Palindrome Linked List.