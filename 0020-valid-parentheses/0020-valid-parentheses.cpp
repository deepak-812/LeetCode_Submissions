class Solution {
public:
    bool isValid(string s) {
       stack<int> st;
       int len=s.length();
       unordered_map<char , int> mp={{')',3},{'}',2},{']',1}};

       for(int i=0;i<len;i++)
       {
        if(s[i]=='(')st.emplace(-3);
        if(s[i]=='{')st.emplace(-2);
        if(s[i]=='[')st.emplace(-1);

        if(s[i]==']' || s[i]=='}' || s[i]==')')
        {
            if(st.empty())return false;
            int n=st.top()+mp[s[i]];
            if(n!=0)return false;
            st.pop();
        }
       }

       if(st.empty())return true;
       else return false;
    }
};
