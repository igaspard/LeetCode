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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) break;
        }
        
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        
        ListNode *start = head;
        while (start != slow) {
            start = start->next;
            slow = slow->next;
        }
        
        return start;
    }
};

// Fast and slow algorithms
// Runtime: 8 ms, faster than 93.43% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 7.6 MB, less than 97.70% of C++ online submissions for Linked List Cycle II.