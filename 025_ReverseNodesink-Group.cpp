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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int len = 0;
        ListNode *tmp = head;
        while (tmp != nullptr) {
            len++;
            tmp = tmp->next;
        }

        if (len < k) return head;

        int remainder = len % k;
        tmp = head;
        for (int i = 1; i < len - remainder; i += k) {
            tmp = reverseBetween(tmp, i, i + k - 1);
        }

        return tmp;
    }

   private:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode *cur = head, *pre = nullptr;
        for (int i = 0; cur != nullptr && i < m - 1; ++i) {
            pre = cur;
            cur = cur->next;
        }
        ListNode *m_minus1 = pre;
        ListNode *m_node = cur;

        ListNode *next = nullptr;
        for (int i = m; cur != nullptr && i < n + 1; ++i) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        if (m_minus1 != nullptr)
            m_minus1->next = pre;
        else
            head = pre;

        m_node->next = cur;

        return head;
    }
};

// Runtime: 24 ms, faster than 34.70% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 11.6 MB, less than 22.55% of C++ online submissions for Reverse Nodes in k-Group.