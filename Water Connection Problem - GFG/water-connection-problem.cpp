//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    bool dfs(int node,int &last,int &minwt,vector<bool> &vis,vector<pair<int,int>> adj[],bool &flag){
        vis[node]=true;
        for(auto it:adj[node]){
            int child=it.first;
            int wght=it.second;
            if(!vis[child]){
                minwt=min(wght,minwt);
                if(!dfs(child,last,minwt,vis,adj,flag))return false;
            }
            else{
                return false;
            }
        }
        if(flag){
            last=node;
            flag=false;
        }
        return true;
    }
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d){
        // code here
         vector<pair<int,int>> adj[n+1];
         vector<bool> vis(n+1,false);
         int in[n+1]={0};
         for(int i=0;i<a.size();i++){
             int u=a[i] ,v=b[i] , wt=d[i];
             in[v]++;
             adj[u].push_back({v,wt});
         }
         vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            if(!in[i]){
                int start=i;
                int last;
                bool flag=true;
                int minwt=INT_MAX;
                if(dfs(i,last,minwt,vis,adj,flag)){
                    if(start==last)continue;
                    ans.push_back({start,last,minwt});
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends