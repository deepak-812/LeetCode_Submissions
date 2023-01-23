class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        int i=0,j=0,ans=0;
        unordered_map<char,int> mp;
        while(j<len){
            if(mp.find(s[j])!=mp.end()){
                while(s[i]!=s[j]){
                    mp.erase(s[i]);
                    i++;
                }
                if(s[i]==s[j]){
                    mp.erase(s[i]);
                    i++;
                }
            }
            mp[s[j]]++;
            int sz=mp.size();
            ans=max(sz,ans);
            j++;
        }
        return ans;
    }
};