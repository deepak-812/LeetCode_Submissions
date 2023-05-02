class Solution {
public:
    int arraySign(vector<int>& nums) {
        int prod=1;
        for(auto n:nums){
            if(n==0){
                prod=0;
                break;
            }
            prod*=n>0?1:-1;
        }   
        return prod;
    }
};