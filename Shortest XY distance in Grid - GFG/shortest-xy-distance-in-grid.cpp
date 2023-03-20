//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int r,int c,int n,int m,vector<vector<char>> &grid){
        if(r<0 || c<0 || c>=m || r>=n || grid[r][c]=='X')return false;
        return true;
    }
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        vector<int> dx={-1,0,1,0} , dy={0,-1,0,1};
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]=='X'){
                    q.push({{i,j},0});
                }
            }
        }
        bool flag=true;
        int ans=INT_MAX;
        while(flag){
            int sze=q.size();
            for(int i=0;i<q.size();i++){
                int y=q.front().first.first;
                int x=q.front().first.second;
                int d=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if(isValid(y+dy[k],x+dx[k],N,M,grid)){
                        q.push({{y+dy[k],x+dx[k]},d+1});
                        if(grid[y+dy[k]][x+dx[k]]=='Y'){
                            ans=d+1;
                            flag=false;
                            break;
                        }
                        grid[y+dy[k]][x+dx[k]]='X';
                    }
                }
                if(!flag){
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends