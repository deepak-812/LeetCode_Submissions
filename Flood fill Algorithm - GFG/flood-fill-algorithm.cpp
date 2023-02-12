//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int n,m,initial;
    void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<bool>> &vis,int newColor,vector<int> &dx,vector<int> &dy ){
        vis[r][c]=true;
        grid[r][c]=newColor;
        for(int i=0;i<4;i++){
            int x=r+dx[i];
            int y=c+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]==initial){
                dfs(x,y,grid,vis,newColor,dx,dy);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        n=image.size() , m=image[0].size();
        initial=image[sr][sc];
        vector<int> dx={1,0,-1,0} , dy={0,-1,0,1};
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int initial=image[sr][sc];
        vector<vector<int>> grid(image.begin(),image.end());
        dfs(sr,sc,grid,vis,newColor,dx,dy);
        return grid;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends