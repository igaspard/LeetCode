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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k <= 0)
            return head;
        
        int len = 0;
        ListNode *tmp = head, *last = nullptr;
        while(tmp != nullptr) {
            last = tmp;
            tmp = tmp->next;
            ++len;
        }
        last->next = head;

        ListNode *lastk = head, *lastk_minus1 = nullptr;
        int rotations =  len - (k % len);
        for(int i = 0; i < rotations; ++i) {
            lastk_minus1 = lastk;
            lastk = lastk->next;
        }
        

        lastk_minus1->next = nullptr;
        head = lastk;
        
        return head;
    }
};

// Runtime: 4 ms, faster than 98.06% of C++ online submissions for Rotate List.
// Memory Usage: 11.9 MB, less than 15.55% of C++ online submissions for Rotate List.