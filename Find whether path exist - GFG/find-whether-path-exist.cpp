//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    bool isValid(int r,int c,vector<vector<int>> &grid,int n){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]==0)return false;
        return true;
    }
    //Function to find whether a path exists from the source to destination.
    bool dfs(int r,int c,vector<vector<int>> &grid,int n){
        if(grid[r][c]==2)return true;
        grid[r][c]=0;
        vector<int> dx={-1,0,1,0} , dy={0,-1,0,1};
        for(int k=0;k<4;k++){
            if(isValid(r+dy[k],c+dx[k],grid,n)){
                if(dfs(r+dy[k],c+dx[k],grid,n))return true;
            }
        }
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return dfs(i,j,grid,n);
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends