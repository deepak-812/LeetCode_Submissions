//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int k){
    // Your Code here
    if((!head || k<=0) || k>num){
        return head;
    }
    Node* curr=head,*prv=NULL;
    while(curr && k>1){
        prv=curr;
        curr=curr->next , k--;
    }
    Node* ptr=curr,*nd=head,*prev=NULL;
    while(curr && curr->next){
        prev=nd;
        nd=nd->next;
        curr=curr->next;
    }
    if(ptr==prev){ // Check for self pointer
        if(prv)prv->next=nd;
            Node* tmp=nd->next;
            nd->next=ptr;
            ptr->next=tmp;
            return head;
    }
    if(prv){
        prv->next=nd;
    }
    else{
        head=nd;
    }
    Node* tmp=ptr->next;
    ptr->next=nd->next;
    nd->next=tmp;
    if(prev && ptr!=prev->next)prev->next=ptr;
    else{
        head=ptr;
    }
    return head;
}
