class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(auto n:nums){
            mp[n]++;
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second>(nums.size())/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};