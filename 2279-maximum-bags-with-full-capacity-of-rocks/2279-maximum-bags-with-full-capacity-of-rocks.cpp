class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extras) {
        int len=capacity.size();
        vector<int> diff(len,0);
        for(int i=0;i<len;i++){
            diff[i]=capacity[i]-rocks[i];
        }
        int ans=0;
        sort(diff.begin(),diff.end());
        for(int i=0;i<len && extras>=0;i++){
            if(diff[i]==0 || extras-diff[i]>=0){
                ans++ , extras-=diff[i];
            }
        }
        return ans;
    }
};