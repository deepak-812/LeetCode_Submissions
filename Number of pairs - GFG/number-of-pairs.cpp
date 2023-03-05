//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        void dfs(int node,vector<bool> &vis,vector<int> adj[],int &nodeCount){
            vis[node]=true;
            nodeCount++;
            for(auto child:adj[node]){
                if(!vis[child]){
                    dfs(child,vis,adj,nodeCount);
                }
            }
        }
        long long int numberOfPairs(vector<vector<int>> &pairs,int p,int n){
            // code here
            vector<int> adj[n];
            long long ans=0;
            for(int i=0;i<p;i++){
                adj[pairs[i][0]].push_back(pairs[i][1]);
                adj[pairs[i][1]].push_back(pairs[i][0]);
            }
            vector<long long int> prs;
            vector<bool> vis(n,false);
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int nodeCount=0;
                    dfs(i,vis,adj,nodeCount);
                    prs.push_back(nodeCount);
                }
            }
            n=prs.size();
            if(n<=1)return 0;
            vector<int> suffixSum(n,0);
            suffixSum[n-1]=prs[n-1];
            for(int i=n-2;i>=0;i--){
                suffixSum[i]=suffixSum[i+1]+prs[i];
            }
            for(int i=1;i<n;i++){
                ans+=prs[i-1]*suffixSum[i];
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        vector<vector<int>> pairs(p,vector<int>(2));
        for(auto &i:pairs)
            for(auto &j:i)
                cin>>j;
        Solution a;
        cout<<a.numberOfPairs(pairs,p,n)<<endl;
    }
}
// } Driver Code Ends