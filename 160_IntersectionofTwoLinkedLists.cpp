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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> hash;
        
        ListNode *cur = headA;
        while(cur != nullptr) {
            hash.insert(cur);
            cur = cur->next;
        }
        
        cur = headB;
        while(cur != nullptr) {
            auto it = hash.find(cur);
            if (it != hash.end())
                return *it;
            cur = cur->next;
        }
        
        return nullptr;
    }
};

// Runtime: 88 ms, faster than 20.93% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage: 18.1 MB, less than 8.80% of C++ online submissions for Intersection of Two Linked Lists.