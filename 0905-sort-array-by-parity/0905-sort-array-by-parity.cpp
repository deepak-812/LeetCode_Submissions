class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
     vector<int> ans(nums.size(),0);
        int j=0 , k=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2){
                ans[k--]=nums[i];
            }
            else{
                ans[j++]=nums[i];
            }
        }
        return ans;
    }
};