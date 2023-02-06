class Solution {
public:
    bool checkInclusion(string p, string s) {
        int sLen=s.length(),pLen=p.length();
        vector<int> sFreq(26,0),pFreq(26,0);
        if(pLen>sLen)return false;
        for(auto it:p){
            pFreq[it-'a']++;
        }
        int l=0,r=0;
        while(r<pLen-1){
            sFreq[s[r]-'a']++ , r++;
        }
        while(r<sLen){
            bool flag=true;
            sFreq[s[r]-'a']++;
            for(int i=0;i<26;i++){
                if(sFreq[i]!=pFreq[i])flag=false;
            }
            if(flag)return true;
            sFreq[s[l]-'a']--;
            l++ , r++;
        }
        return false;
    }
};