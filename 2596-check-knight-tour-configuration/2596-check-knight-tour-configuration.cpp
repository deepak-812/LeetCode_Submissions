class Solution {
private:
    bool isValid(int r,int c,int num,vector<vector<int>> &grid){
        int n=grid.size();
        if(r>=n || c>=n || c<0 || r<0 || grid[r][c]!=num)return false;
        return true;
    }
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int num=0;
        vector<int> dx={-2,-1,1,2,2,1,-1,-2} , dy={-1,-2,-2,-1,1,2,2,1};
        int n=grid.size();
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            num++;
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                if(isValid(y+dy[i],x+dx[i],num,grid)){
                    q.push({y+dy[i],x+dx[i]});
                    break;
                }
            }
        }
        return num==n*n;
    }
};