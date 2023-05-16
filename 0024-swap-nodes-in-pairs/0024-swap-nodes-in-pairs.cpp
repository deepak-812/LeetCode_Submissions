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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next))return head;
        
        ListNode *ptr=head->next , *prv=head;
        while(ptr)
        {
            int a=ptr->val;
            ptr->val=prv->val;
            prv->val=a;
            ptr=ptr->next;
            if(ptr)
                prv=ptr , ptr=ptr->next;
        }
        return head;
    }
};