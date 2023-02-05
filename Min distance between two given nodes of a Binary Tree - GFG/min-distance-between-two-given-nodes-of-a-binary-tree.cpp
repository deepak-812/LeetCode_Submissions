//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int dist;
    unordered_map<Node*,Node*> par;
    unordered_map<Node*,bool> vis;
    int findDist(Node* root, int a, int b) {
        // Your code here
        queue<Node*> q;
        if(!root){
            return -1;
        }
        q.push(root);
        Node* fnd=NULL;
        par[root]=NULL;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node* curr=q.front();
                vis[curr]=false;
                if(curr->data==a){
                    fnd=curr;
                }
                if(curr->left){
                    par[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    par[curr->right]=curr;
                    q.push(curr->right);
                }
                q.pop();
            }
        }
        if(!fnd){
            return 0;
        }
        dist=INT_MAX;
        dfs(fnd,0,b);
        if(dist==INT_MAX)return -1;
        return dist;
    }
    void dfs(Node* root,int d,int b){
        if(!root){
            return;
        }
        if(root->data==b){
            dist=min(dist,d);
        }
        vis[root]=true;
        if(par[root] && !vis[par[root]]){
            dfs(par[root],d+1,b);
        }
        if(root->left && !vis[root->left]){
            dfs(root->left,d+1,b);
        }
        if(root->right && !vis[root->right]){
            dfs(root->right,d+1,b);
        }
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends