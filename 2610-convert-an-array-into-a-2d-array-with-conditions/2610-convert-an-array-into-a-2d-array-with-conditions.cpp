class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> freq;
        for(auto it:nums){
            freq[it]++;
        }
        vector<vector<int>> ans;
        while(freq.size()){
            vector<int> v;
            for(auto it:freq){
                v.push_back(it.first);
            }
            for(auto it:v){
                freq[it]--;
                if(freq[it]==0){
                    freq.erase(it);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};