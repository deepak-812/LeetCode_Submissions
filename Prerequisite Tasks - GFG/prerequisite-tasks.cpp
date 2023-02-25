//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[n];
	    for(auto it:prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    int indegree[n]={0};
	    for(int i=0;i<n;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    int cnt=0;
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(!indegree[i]){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int task=q.front();
	        q.pop();
	        cnt++;
	        for(auto it:adj[task]){
	            indegree[it]--;
	            if(!indegree[it]){
	                q.push(it);
	            }
	        }
	    }
	    return cnt==n;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends