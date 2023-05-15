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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode *ptr=head , *prv=head;
        
        while(--k)ptr=ptr->next;
        
        ListNode *tmp=ptr;
        
        while(ptr->next)prv=prv->next , ptr=ptr->next;
        
        int a=tmp->val;
        tmp->val=prv->val;
        prv->val=a;

     return head;
    }
};