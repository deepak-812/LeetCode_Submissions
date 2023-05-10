class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat;
        for(int i=1;i<=n;i++){
            vector<int> v(n);
            mat.push_back(v);
        }
        
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        
        vector<int> steps{n,n-1};
        
        int currDir=0;
        int r=0,c=-1,val=1;
        while(steps[currDir%2]){
            for(int i=0;i<steps[currDir%2];++i){
                r+=dirs[currDir][0] , c+=dirs[currDir][1];
                mat[r][c]=val++;
            }
            steps[currDir%2]-- , currDir=++currDir%4;
        }
        return mat;
    }
};