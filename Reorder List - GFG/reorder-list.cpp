//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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



// } Driver Code Ends
/* Following is the Linked list node structure */

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
    void reorderList(Node* head) {
        // Your code here
        if(!head){
            return;
        }
        stack<Node*> stk;
        Node* curr=head;
        int sz=0;
        while(curr){
            stk.push(curr);
            sz++;
            curr=curr->next;
        }
        curr=head;
        int k=sz/2;
        if(sz%2){
            k=sz/2+1;
        }
        Node* last=NULL;
        while(stk.size()>k){
            Node* tmp=curr->next;
            curr->next=stk.top();
            if(last){
                last->next=curr;
            }
            last=stk.top();
            stk.pop();
            curr=tmp;
        }
        if(sz%2){
            if(last)last->next=stk.top();
            last=stk.top();
        }
        last->next=NULL;
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends