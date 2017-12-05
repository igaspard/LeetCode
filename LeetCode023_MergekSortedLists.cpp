// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 // w/o use new node
 class NewSolution {
 public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode *head = NULL, *prev = NULL;

         if(l1==NULL)
             return l2;
         if(l2==NULL)
             return l1;

         if(l1->val > l2->val) {
             head = l2;
             prev = head;
             l2 = l2->next;
         }
         else {
             head = l1;
             prev = head;
             l1 = l1->next;
         }

         while(l1 && l2) {
             if(l1->val > l2->val) {
                 prev->next = l2;
                 prev = l2;
                 l2 = l2->next;
             }
             else {
                 prev->next = l1;
                 prev = l1;
                 l1 = l1->next;
             }
         }

         if(l1==NULL)
             prev->next = l2;
         if(l2==NULL)
             prev->next = l1;

         return head;
     }
     ListNode* mergeKLists(vector<ListNode*>& lists) {
         vector<ListNode*>::size_type i=0, iteration = 1, len = lists.size();
         if(!len)
             return NULL;
         if(len==1)
             return lists[0];

         while(iteration<len) {
             for(vector<ListNode*>::size_type i=0; i<len-iteration; i+=iteration*2)
                 lists[i] = mergeTwoLists(lists[i], lists[i+iteration]);
             iteration*=2;
         }
         return lists[0];
    }
 };
