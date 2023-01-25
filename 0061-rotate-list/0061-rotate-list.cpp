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
    ListNode* rotateRight(ListNode* head, int k) { // T.C. O(n) A.S. O(1)
        if(!head){
            return head;
        }
        ListNode* curr=head,*prev=NULL;
        int sz=0;
        while(curr){
            curr=curr->next;
            sz++;
        }
        k=k%sz;
        if(k==0){
            return head;
        }
        curr=head;
        int x=sz-k;
        prev=NULL;
        while(x>0 && curr){
            prev=curr;
            curr=curr->next , x--;
        }
        prev->next=NULL;
        ListNode* ptr=curr;
        while(curr && curr->next){
            curr=curr->next;
        }
        curr->next=head;
        head=ptr;
        return head;
    }
};