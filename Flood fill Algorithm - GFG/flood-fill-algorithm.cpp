//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
   int n,m;
   bool isValid(int r,int c,vector<vector<int>> image,vector<vector<bool>> &vis,int initial){
       if(r<0 || c<0 || r>=n || c>=m)return false;
       if(image[r][c]!=initial || vis[r][c])return false;
       return true;
   }
public:
    vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor) { //T.C. O(4*n^2) A.S. O(n^2) O(n^2)
        // Code here 
        n=image.size() , m=image[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int initial=image[sr][sc];
        vector<int> dx={1,0,-1,0} , dy={0,-1,0,1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=true;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            image[x][y]=newColor;
            for(int i=0;i<4;i++){
                if(isValid(x+dx[i],y+dy[i],image,vis,initial)){
                    vis[x+dx[i]][y+dy[i]]=true;
                    q.push({x+dx[i],y+dy[i]});
                }
            }
        }
        return image;
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