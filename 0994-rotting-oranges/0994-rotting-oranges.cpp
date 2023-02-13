class Solution {
private:
    int n,m;
    bool isValid(int x,int y,vector<vector<int>> &grid,vector<vector<bool>> &vis){
        if((x>=n || x<0 || y>=m || y<0) || (vis[x][y] || grid[x][y]==0))return false;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {  // A.S. O(m*n)+O(m*n) T.C. O(n)+O(4*n) = O(n) 
        n=grid.size() , m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        vector<int> dx={-1,0,1,0} , dy={0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int sze=q.size();
            for(int i=0;i<sze;i++){
                int x=q.front().first , y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    if(isValid(x+dx[j],y+dy[j],grid,vis)){
                        grid[x+dx[j]][y+dy[j]]=2;
                        q.push({x+dx[j],y+dy[j]});
                        vis[x+dx[j]][y+dy[j]]=true;
                    }
                }
            }
            if(!q.empty())time++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return time;
    }
};