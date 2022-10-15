class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n-1;i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=prev;
            prev2=prev , prev=max(take,nottake);
        }
        int ans=prev;
        if(n==1){
            return prev;
        }
        prev=nums[1];
        prev2=0;
        for(int i=2;i<n;i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=prev;
            prev2=prev , prev=max(take,nottake);
        }
        return max(ans,prev);
    }
};