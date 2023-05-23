class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        else{
            return a.first<b.first;
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size() && k>0;i++){
            ans.push_back(v[i].first);
            --k;
        }
        return ans;
    }
};