//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
     int row,col;
     bool isValid(int r,int c,vector<vector<bool>> &vis,vector<vector<char>> &mat){
         if(r>=row || c>=col || c<0 || r<0 || vis[r][c] || mat[r][c]=='X')return false;
         return true;
     }
     void dfs(int r,int c,vector<vector<bool>> &vis,vector<vector<char>> &mat){
         vector<int> dx={-1,0,1,0} , dy={0,-1,0,1};
         vis[r][c]=true;
         for(int i=0;i<4;i++){
             if(isValid(r+dy[i],c+dx[i],vis,mat)){
                 dfs(r+dy[i],c+dx[i],vis,mat);
             }
         }
     }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        // code here
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        row=n,col=m;
        for(int j=0;j<m;j++){
            // uuper first row
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,vis,mat);
            }
            // lower row
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat);
            }
        }
        for(int j=0;j<n;j++){
            // left first col
            if(!vis[j][0] && mat[j][0]=='O'){
                dfs(j,0,vis,mat);
            }
            // right first col
            if(!vis[j][m-1] && mat[j][m-1]=='O'){
                dfs(j,m-1,vis,mat);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends