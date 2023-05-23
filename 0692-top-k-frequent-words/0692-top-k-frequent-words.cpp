class Solution {
public:
    static bool cmp(pair<string,int> a,pair<string,int> b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();++i){
            mp[words[i]]++;
        }
        vector<pair<string,int>> v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size() && k;i++){
            ans.push_back(v[i].first);
            k--;
        }
        return ans;
    }
};