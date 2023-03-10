class Solution {
public:
    bool check(vector<int> &piles,long long mid,int h){
        long long cnt=0;
        for(auto it:piles){
            if(it%mid==0){
                cnt+=it/mid;
            }
            else{
                cnt+=it/mid+1;
            }
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long totpiles=piles.size();
        if(h<totpiles)return -1;
        long long ans;
        int lo=1 , hi=INT_MIN , mid;
        for(auto it:piles){
            hi=max(it,hi);
        }
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(check(piles,mid,h)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};