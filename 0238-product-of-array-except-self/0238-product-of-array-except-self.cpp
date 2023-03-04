class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt=0;
        int prod=1;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++ , ind=i;
            }
            else{
                prod*=nums[i];
            }
        }
        vector<int> ans(nums.size(),0);
        if(cnt>1){
            return ans;
        }
        if(cnt==1){
            ans[ind]=prod;
        }
        else{
            for(int i=0;i<nums.size();i++){
                ans[i]=prod/nums[i];
             }   
        }
        return ans;
    }
};