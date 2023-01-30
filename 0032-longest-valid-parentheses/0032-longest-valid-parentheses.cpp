class Solution {
public:
    int longestValidParentheses(string s) { // T.C. O(n) and A.S. O(n)
        stack<int> stk;
        int ans=0,len=s.length();
        if(!len)return ans;
        stk.push(-1);
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else{
                if(!stk.empty()){
                    stk.pop();
                }
                if(!stk.empty()){
                    ans=max(ans,i-stk.top());
                }
                else{
                    stk.push(i);
                }
            }
        }
        return ans;
    }
};