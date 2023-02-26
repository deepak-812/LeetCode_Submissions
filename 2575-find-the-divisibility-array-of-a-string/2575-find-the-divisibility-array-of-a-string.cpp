class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.length(),0);
        long long int val=0;
        for(int i=0;i<word.length();i++){
            val=(val*10+(word[i]-'0'))%m;
            if(!val)ans[i]=1;
        }
        return ans;
    }
};