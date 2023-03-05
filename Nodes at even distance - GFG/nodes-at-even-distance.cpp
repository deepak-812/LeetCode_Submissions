//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int countOfNodes(vector<int> graph[], int n){
        // code here
        vector<int> odd,even;
        vector<bool> vis(n+1,false);
        queue<int> q;
        int lvl=0;
        q.push(1);
        vis[1]=true;
        while(!q.empty()){
            lvl++;
            int sze=q.size();
            for(int i=0;i<sze;i++){
                int node=q.front();
                if(lvl%2){
                    odd.push_back(node);
                }
                else{
                    even.push_back(node);
                }
                q.pop();
                for(auto it:graph[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }
        }
        return ((odd.size()-1)*(odd.size()))/2+((even.size()-1)*(even.size()))/2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends