class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                if(!stk.empty())stk.pop();
                continue;
            }
            stk.push(s[i]);
        }
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};