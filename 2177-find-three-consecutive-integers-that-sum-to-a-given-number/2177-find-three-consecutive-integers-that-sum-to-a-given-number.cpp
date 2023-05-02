class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num%3){
            return ans;
        }
        long long n=num/3;
        ans={n-1,n,n+1};
        return ans;
    }
};