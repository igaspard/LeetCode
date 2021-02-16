/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 != nullptr) {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while (p2 != nullptr) {
            s2.push(p2->val);
            p2 = p2->next;
        }
        
        int carry = 0;
        ListNode *pre = nullptr;
        while(!s1.empty() || !s2.empty()) {
            int n1 = !s1.empty() ? s1.top() : 0;
            int n2 = !s2.empty() ? s2.top() : 0;
            int sum = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;

            ListNode *tmp = new ListNode(sum);
            tmp->next = pre;
            pre = tmp;
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
        }

        if (carry != 0) {
            ListNode *tmp = new ListNode(carry);
            tmp->next = pre;
            pre = tmp;
        }

        return pre;
    }
};
// @lc code=end

