class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size() , n=grid[0].size();
        vector<vector<int>> v(m,vector<int> (n,false));
        v[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            v[i][0]=v[i-1][0]+grid[i][0];
        }
        for(int j=1;j<n;j++){
            v[0][j]=v[0][j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                v[i][j]=grid[i][j]+min(v[i-1][j],v[i][j-1]);
            }
        }
        return v[m-1][n-1];
    }
};