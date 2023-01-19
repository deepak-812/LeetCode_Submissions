class Solution {
public:
    int maxSubArray(vector<int>& nums) { // Kadane's Algorithm T.C. O(n) and A.S. O(1)
        long long sum=0,ans=INT_MIN;
        for(auto it:nums){
            sum+=it;
            ans=max(ans,sum);
            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
};