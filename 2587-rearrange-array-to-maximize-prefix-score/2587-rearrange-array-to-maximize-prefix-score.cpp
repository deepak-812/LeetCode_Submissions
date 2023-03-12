class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long sum=0;
        int cnt=0;
        for(auto it:nums){
            if(sum+it<=0){
                break;
            }
            cnt++ , sum+=it;
        }
        return cnt;
    }
};