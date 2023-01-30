class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        int i=0,j=0,ans=0;
        bool vis[256]={false};
        while(j<len){
            if(vis[s[j]]){
                while(s[i]!=s[j]){
                    vis[s[i]]=false;
                    i++;
                }
                if(s[i]==s[j]){
                    vis[s[i]]=false;
                    i++;
                }
            }
            vis[s[j]]=true;
            ans=max(j-i+1,ans);
            j++;
        }
        ans=max(j-i,ans);
        return ans;
    }
};