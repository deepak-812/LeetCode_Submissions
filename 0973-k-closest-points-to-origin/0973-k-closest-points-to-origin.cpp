class Solution {
public:
    static bool cmp(pair<vector<int>,double> a,pair<vector<int>,double> b){
        if(a.second!=b.second){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<vector<int>,double>> v;
        for(int i=0;i<points.size();++i){
            v.push_back({points[i],sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1])});
        }
        vector<vector<int>> ans;
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size() && k>0;i++){
            ans.push_back(v[i].first);
            --k;
        }
        return ans;
    }
};