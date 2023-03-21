class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int l=0,r=0,len=nums.size();
        long long ans=0;
        while(r<nums.size()){
            if(nums[r]==0){
                l=r;
                while(r<len && nums[r]==0){
                    r++;
                }
                r--;
                int n = r-l+1;
                ans+=(1LL*(n)*(n+1))/2;
            }
            r++;
        }
        return ans;
    }
};