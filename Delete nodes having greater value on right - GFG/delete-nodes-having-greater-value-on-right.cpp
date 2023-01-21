//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head){
        // your code goes here
        if(!head){
            return head;
        }
        Node* curr=head;
        Node* start=NULL,*last=NULL;
        stack<Node*> as,stk,tmp;
        while(curr){
            as.push(curr);
            curr=curr->next;
        }
        while(!as.empty()){
            while(stk.empty()==false && stk.top()->data<=as.top()->data){
                stk.pop();
            }
            if(stk.empty()){
               tmp.push(as.top());
            }
            stk.push(as.top());
            as.pop();
        }
        while(!tmp.empty()){
            if(!start){
                start=tmp.top();
            }
            else{
                last->next=tmp.top();
            }
            last=tmp.top();
            tmp.pop();
        }
        return start;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends