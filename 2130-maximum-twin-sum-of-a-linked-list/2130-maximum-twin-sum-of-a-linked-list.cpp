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
    int pairSum(ListNode* head) {
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;  //max heap
        
        if(!head && !(head->next))return 0;
        
        ListNode *ptr=head;
        
        while(ptr)
            st.emplace(ptr->val) , q.emplace(ptr->val) , ptr=ptr->next;
        while(!st.empty())
            pq.push(q.front()+st.top()) , st.pop() , q.pop();
     return pq.top();
    }
};