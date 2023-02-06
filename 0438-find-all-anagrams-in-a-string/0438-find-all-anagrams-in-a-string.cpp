class Solution {
public:
    vector<int> findAnagrams(string s, string p) { //  T.C. O(26*n) A.S. O(26) or A.S. O(1) 
        vector<int> pFreq(26,0);
        vector<int> sFreq(26,0);
        int sLen=s.length(),pLen=p.length();
        vector<int> ans;
        if(pLen>sLen)return ans;
        for(auto it:p){
            pFreq[it-'a']++;
        }
        int l=0,r=0;
        while(r<pLen-1){
            sFreq[s[r]-'a']++, r++;
        }
        while(r<sLen){
            bool flag=true;
            sFreq[s[r]-'a']++;
            for(int i=0;i<26;i++){
                if(pFreq[i]!=sFreq[i])flag=false;
            }
            if(flag)ans.push_back(l);
            sFreq[s[l]-'a']--;
            l++ , r++;
        }
        return ans;
    }
};