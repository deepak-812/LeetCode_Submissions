class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,i=0,j=0,n=nums.size();
        int ans=INT_MAX;
        while(j<n){
            sum+=nums[j];
            if(sum>=target){
                while(sum>=target && i<=j){
                    sum-=nums[i];
                    ans=min(j-i+1,ans) , i++;
                }
            }
            j++;
        }
        if(ans==INT_MAX){
            ans=0;
        }
        return ans;
    }
};