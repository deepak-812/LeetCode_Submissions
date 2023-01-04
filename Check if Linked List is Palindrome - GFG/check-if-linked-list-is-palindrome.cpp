//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(!head){
            return false;
        }
        if(head && !head->next){
            return true;
        }
        int sze=2;
        Node* curr=head->next;
        Node* prev=head;
        while(curr && curr->next){
            curr=curr->next;
            prev=prev->next;
            sze++;
            if(curr && curr->next){
                curr=curr->next;
                sze++;
            }
        }
        if(sze%2==0){
            prev=prev->next;
        }
        stack<Node*> st;
        while(prev){
            st.push(prev);
            prev=prev->next;
        }
        curr=head;
        while(st.empty()==false){
            if(curr->data!=st.top()->data){
                return false;
            }
            curr=curr->next;
            st.pop();
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends