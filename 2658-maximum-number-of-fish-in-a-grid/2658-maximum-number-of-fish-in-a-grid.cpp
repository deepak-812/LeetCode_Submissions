class Solution {
public:
    int m,n;
    bool isValid(int r,int c,vector<vector<int>> &grid){
        if(r<0 || c<0 || r>=m || c>=n || !grid[r][c]){
            return false;
        }
        return true;
    }
    void dfs(int r,int c,int &fishes,vector<vector<int>> &grid){
        vector<int> dx={-1,0,1,0} ,dy={0,-1,0,1};
        fishes+=grid[r][c];
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            if(isValid(r+dy[i],c+dx[i],grid)){
                dfs(r+dy[i],c+dx[i],fishes,grid);
            }
        }
        
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        m=grid.size() , n=grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]){
                    int fishes=0;
                    dfs(i,j,fishes,grid);
                    ans=max(ans,fishes);
                }
            }
        }
        return ans;
    }
};