class Solution { // T.C. O(m*n) and S.C. O(1)
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
// Like this Use of only one Var to maintain dirs ind and steps and use of dirs and steps Too much Briliant
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> res;
        
        if(!m)return res;
        
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        
        vector<int> steps{n,m-1}; 
// bcz in first round n cols Traversed and then move 1 steps less in second round in downward Direction
        int currDir=0;
        int r=0,c=-1; 
// bcz c increment 1 step in every step of 1sr round so initailly it is -1 so that after increament it is 0
        while(steps[currDir%2]){
            for(int i=0;i<steps[currDir%2];++i){
                r+=dirs[currDir][0] , c+=dirs[currDir][1];
                res.push_back(matrix[r][c]);
            }
            steps[currDir%2]-- , currDir=++currDir%4;
        } 
        return res;
    }
};