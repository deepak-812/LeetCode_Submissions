//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    private:
        int m,n;
        bool isValid(int x,int y,vector<vector<int>> &grid,vector<vector<bool>> &vis){
            if(y>=m || y<0 || x>=n || x<0)return false;
            if(grid[x][y]==0 || vis[x][y])return false;
            return true;
        }
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int time=0;
        n=grid.size() , m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<int> dx={-1,0,1,0} , dy={0,-1,0,1};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int sze=q.size();
            bool flag=true;
            for(int i=0;i<sze;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int d=0;d<4;d++){
                    if(isValid(x+dx[d],y+dy[d],grid,vis)){
                        flag=false;
                        vis[x+dx[d]][y+dy[d]]=true;
                        grid[x+dx[d]][y+dy[d]]=2;
                        q.push({x+dx[d],y+dy[d]});
                    }
                }
            }
            if(!flag)time++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return time;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends