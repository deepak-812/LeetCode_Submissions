//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int dfs(Node* root,int &ans){
       if(!root)return INT_MIN;
       auto lft=dfs(root->left,ans);
       auto rght=dfs(root->right,ans);
       int val;
       if((lft==INT_MIN) && (rght==INT_MIN)){
           val=root->data;
       }
       else if(lft!=INT_MIN && rght!=INT_MIN){
           ans=max(lft+rght+root->data,ans);
           val=max(lft,rght)+root->data;
       }
       else if(lft!=INT_MIN){
           val=lft+root->data;
       }
       else{
           val=rght+root->data;
       }
       return val;
    }
    int solve(Node* root){
        if(!root)return INT_MIN;
        int val=max(solve(root->left),solve(root->right));
        if(val==INT_MIN)val=0;
        return val+root->data;
    }
    int maxPathSum(Node* root){
        // code here
        int ans=INT_MIN;
        dfs(root,ans);
        if(root->left==NULL || root->right==NULL)ans=max(solve(root),ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends