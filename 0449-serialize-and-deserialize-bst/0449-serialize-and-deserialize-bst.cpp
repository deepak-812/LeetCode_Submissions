/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            if(!curr){
                s+="#,";
            }
            else{
                s+=to_string(curr->val);
                s+=",";
            }
            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }
            q.pop();
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size())return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false){
            str="";
            getline(s,str,',');
            TreeNode* curr=q.front();
            if(str=="#"){
                curr->left=NULL;
            }
            else{
                curr->left=new TreeNode(stoi(str));
                q.push(curr->left);
            }
            str="";
            getline(s,str,',');
            if(str=="#"){
                curr->right=NULL;
            }
            else{
                curr->right=new TreeNode(stoi(str));
                q.push(curr->right);
            }
            q.pop();
        }
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;