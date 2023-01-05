//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        vector<int> v1;
        while(first){
            v1.push_back(first->data);
            first=first->next;
        }
        vector<int> v2;
        while(second){
            v2.push_back(second->data);
            second=second->next;
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        int carry=0;
        int i=0,len;
        vector<int> a;
        len=v1.size()>v2.size()?v2.size():v1.size();
        while(i<len){
            int n=v1[i]+v2[i]+carry;
            a.push_back(n%10);
            carry=n/10;
            i++;
        }
        while(i<v1.size()){
            int n=v1[i]+carry;
            a.push_back(n%10);
            carry=n/10;
            i++;
        }
        while(i<v2.size()){
            int n=v2[i]+carry;
            a.push_back(n%10);
            carry=n/10;
            i++;
        }
        if(carry){
            a.push_back(carry);
        }
        reverse(a.begin(),a.end());
        struct Node* start=NULL,*last;
        i=0;
        while(i<a.size()){
            struct Node* nd=new Node(a[i]);
            if(!start){
                last=start=nd;
            }
            else{
                last->next=nd;
            }
            last=nd;
            i++;
        }
        return start;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends