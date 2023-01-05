class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int endPoint=INT_MAX;
        int ans=1;
        for(auto it:points){
            int start=it[0];
            int end=it[1];
            if(start>endPoint){
                ans++;
                endPoint=end;
            }
            else{
                endPoint=min(endPoint,end);
            }
        }
        return ans;
    }
};