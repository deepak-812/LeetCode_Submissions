class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<int> v;
        int m=score.size(),n=score[0].size();
        for(int i=0;i<m;i++){
            v.push_back(score[i][k]);
        }
        sort(v.begin(),v.end(),greater<int>());
        vector<vector<int>> ans;
        for(int x=0;x<m;x++){
            for(int i=0;i<m;i++){
                if(score[i][k]==v[x]){
                    ans.push_back(score[i]);
                    break;
                }
            }
        }
        return ans;
    }
};