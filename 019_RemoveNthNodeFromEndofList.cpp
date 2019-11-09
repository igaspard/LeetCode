#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class StackSolution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        if (!head)
            return head;

        ListNode *tmp = head;
        stack<ListNode*> s;
        while (tmp) {
            s.push(tmp);
            tmp = tmp->next;
        }
        ListNode *del, *prev=NULL;
        while (n>0) {
            del = s.top();
            s.pop();
            n--;
        }
        cout<<del->val;
        if(!s.empty()) {
            prev = s.top();
            prev->next = del->next;
        }
        if(del == head)
            head = head->next;
        free(del);
        return head;
    }
}
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return head;

        ListNode *tmp = head;
        int len = 1;
        // Count the list
        while (tmp->next) {
            tmp = tmp->next;
            len++;
        }
        // move d and p to i-n
        ListNode *del = head, *prev = NULL;
        int target = len - n;
        while(target > 0) {
            prev = del;
            del = del->next;
            target--;
        };
        cout<<del->val;
        if(prev)
            prev->next = del->next;
        if(del == head)
            head = head->next;
        delete del;
        return head;
    }
};
