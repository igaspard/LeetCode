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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *fast = head, *slow = head;
        
        while(fast != nullptr && slow != nullptr) {
            slow = slow->next;
            if (fast->next != nullptr)
                fast = fast->next->next;
            else
                return false;
            if (fast == slow)
                return true;
        }
        
        return false;
    }
};

// Runtime: 8 ms, faster than 95.87% of C++ online submissions for Linked List Cycle.
// Memory Usage: 7.9 MB, less than 33.78% of C++ online submissions for Linked List Cycle.