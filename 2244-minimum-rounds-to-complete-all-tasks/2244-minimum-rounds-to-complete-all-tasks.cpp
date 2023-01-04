class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(auto c:tasks){
            mp[c]++;
        }
        int ans=0;
        for(auto &it:mp){
            while(it.second>4){
                mp[it.first]-=3;
                ans++;
            }
            if(it.second==3){
                mp[it.first]-=3;
                ans++;
            }
            while(it.second>1){
                mp[it.first]-=2;
                ans++;
            }
            if(it.second==1){
                return -1;
            }
        }
        return ans;
    }
};