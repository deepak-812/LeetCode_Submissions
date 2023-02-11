//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) {
	    // code here
	    bool vis[10001]={false};
	    queue<int> q;
	    int levelOfNode;
	    for(int i=0;i<v;i++){
	        if(!vis[i]){
	            levelOfNode=0;
	            vis[i]=true;
	            q.push(i);
	            while(!q.empty()){
	                int sze=q.size();
	                for(int i=0;i<sze;i++){
	                    int node=q.front();
	                    if(node==x)return levelOfNode;
	                    for(auto child:adj[node]){
	                        if(!vis[child]){
	                            vis[child]=true;
	                            q.push(child);
	                        }
	                    }
	                    q.pop();
	                }
	                levelOfNode++;
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends