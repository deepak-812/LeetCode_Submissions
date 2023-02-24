//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    vector<int> col;
public:
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    col.resize(v,-1);
	    queue<int> q;
	    for(int i=0;i<v;i++){
	        if(col[i]==-1){
	            q.push(i);
	            col[i]=0;
	             while(!q.empty()){
	                 int node=q.front();
	                 q.pop();
	                 for(auto child:adj[node]){
	                     if(col[child]==-1){
	                         col[child]=col[node]^1;
	                         q.push(child);
	                     }
	                     else if(col[child]==col[node]){
	                         return false;
	                     }
	                 }
	            }
	         }   
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends