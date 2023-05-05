class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int len=0;
        int l=0,r=0;
        while(r<s.length()){
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u'){
                len++;
            }
            if(r-l+1==k){
                ans=max(len,ans);
                if(s[l]=='a' || s[l]=='e' || s[l]=='o' || s[l]=='i' || s[l]=='u'){
                    len--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};