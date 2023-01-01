class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> word;
        string str;
        int i=0;
        for(;i<s.size();i++){
            if(s[i]==' '){
                word.push_back(str);
                str="";
            }
            else
                str+=s[i];
        }
        word.push_back(str);
        set<string> st;
        unordered_map<char,string> mp;
        if(word.size()!=pattern.size())return false;
        for(i=0;i<word.size();i++){
            if(mp.find(pattern[i])!=mp.end()){
                if(mp[pattern[i]]!=word[i]){
                    return false;
                }
            }
            else{
                mp[pattern[i]]=word[i];
            }
            st.insert(word[i]);
        }
        return st.size()==mp.size();
    }
};