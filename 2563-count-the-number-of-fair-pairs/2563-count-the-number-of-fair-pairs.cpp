class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        if(nums.size()<=1)return 0;
        deque<int> dq;
        sort(nums.begin(),nums.end());
        for(auto n:nums)dq.push_back(n);
        for(int i=0;i<nums.size();i++){
            dq.pop_front();
            auto it=lower_bound(dq.begin(),dq.end(),lower-nums[i]);
            auto it1=upper_bound(dq.begin(),dq.end(),upper-nums[i]);
            ans+=it1-it;
        }
        return ans;
    }
};