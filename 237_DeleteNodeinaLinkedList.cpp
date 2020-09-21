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
    void deleteNode(ListNode* node) {
        ListNode *tmp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete tmp;
    }
};

// Since we don't have the previous node, we replace the value of current node with the next

// Runtime: 12 ms, faster than 98.74% of C++ online submissions for Delete Node in a Linked List.
// Memory Usage: 8.1 MB, less than 44.07% of C++ online submissions for Delete Node in a Linked List.