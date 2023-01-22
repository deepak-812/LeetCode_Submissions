//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* curr=head,*startE=NULL,*start=NULL,*lastE=NULL,*last=NULL;
        if(!head){
            return head;
        }
        while(curr){
            int value=curr->data;
            if(value%2){
               if(!start){
                   start=curr;
               }
               else{
                   last->next=curr;
               }
               last=curr;
            }
            else{
                if(!startE){
                    startE=curr;
                }
                else{
                    lastE->next=curr;
                }
                lastE=curr;
            }
            curr=curr->next;
        }
        if(last){
            last->next=NULL;
        }
        if(lastE)lastE->next=start;
        else{
            return start;
        }
        return startE;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends