class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int l=0,r=0,ans=0;
        while(r<fruits.size()){
            freq[fruits[r]]++;
            if(freq.size()>2){
                freq[fruits[l]]--;
                if(!freq[fruits[l]])freq.erase(fruits[l]);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};