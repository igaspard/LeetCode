class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        ListNode *p1 = l1, *p2 = l2;
        int carry = 0;
        while (p1 != nullptr || p2 != nullptr) {
            int n1 = (p1 != nullptr) ? p1->val : 0;
            int n2 = (p2 != nullptr) ? p2->val : 0;
            int sum = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;

            cur->next = new ListNode(sum);
            cur = cur->next;
            if (p1 != nullptr) p1 = p1->next;
            if (p2 != nullptr) p2 = p2->next;
        }

        if (carry != 0) {
            cur->next = new ListNode(carry);
        }

        return dummy->next;
    }
};