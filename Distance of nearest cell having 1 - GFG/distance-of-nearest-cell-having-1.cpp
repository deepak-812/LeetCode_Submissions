//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
private:
    int n,m;
    bool isValid(int x,int y,vector<vector<int>> &grid,vector<vector<bool>> &vis){
        if(x<0 || x>=n || y>=m || y<0 || vis[x][y])return false;
        return true;
    }  
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    // Code here
	    n=grid.size() , m=grid[0].size();
	    vector<vector<int>> dist(n,vector<int>(m,0));
	    vector<int> dx={-1,0,1,0} , dy={0,-1,0,1};
	    vector<vector<bool>> vis(n,vector<bool>(m,false));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                vis[i][j]=true;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    while(!q.empty()){
	        int x=q.front().first.first;
	        int y=q.front().first.second;
	        int distance=q.front().second;
	        q.pop();
	        dist[x][y]=distance;
	        for(int d=0;d<4;d++){
	            if(isValid(x+dx[d],y+dy[d],grid,vis)){
	                vis[x+dx[d]][y+dy[d]]=true;
	                q.push({{x+dx[d],y+dy[d]},distance+1});
	            }
	        }
	    }
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends