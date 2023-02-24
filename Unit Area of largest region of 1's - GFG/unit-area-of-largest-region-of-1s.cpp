//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        int rows,cols,ans;
        bool isValid(int r,int c,vector<vector<bool>> &vis,vector<vector<int>> &grid){
            if(r<0 || c<0 || r>=rows || c>=cols || !grid[r][c] || vis[r][c])return false;
            return true;
        }
        void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<bool>> &vis,int &area){
            vis[r][c]=true;
            area++;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(isValid(r+i,c+j,vis,grid)){
                        dfs(r+i,c+j,grid,vis,area);
                    }
                }
            }
        }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans=0;
        rows=grid.size() , cols=grid[0].size();
        vector<vector<bool>> vis(rows,vector<bool> (cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!vis[i][j] && grid[i][j]){
                    int area=0;
                    dfs(i,j,grid,vis,area);
                    ans=max(area,ans);
                }
            }
        }
        return ans;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends