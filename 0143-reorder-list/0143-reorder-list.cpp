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
    void reorderList(ListNode* head) {
        if(!head || !(head->next)){
            return;
        }
        stack<ListNode*> stk;
        ListNode* curr=head;
        while(curr){
            stk.push(curr);
            curr=curr->next;
        }
        int sze=stk.size(),i=1;
        curr=head;
        ListNode* ptr;
        while(i<=sze/2 && curr){
            ptr=stk.top();
            ListNode* tmp=curr->next;
            curr->next=ptr;
            curr=tmp;
            ptr->next=curr , i++;
            stk.pop();
        }
        if(curr==stk.top()){
            ptr->next=curr;
        }
        curr->next=NULL;
    }
};