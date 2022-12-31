class Solution {
public:
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};
    int m,n;
    int ans;
    bool isValid(int x,int y){
        return x<m && y<n && x>=0 && y>=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        pair<int,int> dst,src;
        int empty=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    empty++;
                }
                if(grid[i][j]==1){
                    src={i,j};
                }
                if(grid[i][j]==2){
                    dst={i,j};
                }
            }
        }
        dfs(src.first,src.second,empty,dst,grid);
        return ans;
    }
    void dfs(int x,int y,int empty,pair<int,int> &dst,vector<vector<int>> &grid){
        if(empty==-1 && std::make_pair(x,y)==dst){
            ans++;
        }
        grid[x][y]=-1; // footprint to don't repeat the same visited box in curr way
        for(int i=0;i<4;i++){
            if(isValid(x+dx[i],y+dy[i]) && grid[x+dx[i]][y+dy[i]]!=-1){
                dfs(x+dx[i],y+dy[i],empty-1,dst,grid);
            }
        }
        // Backtrack to again make Visited box as previous
        grid[x][y]=0;
    }
};