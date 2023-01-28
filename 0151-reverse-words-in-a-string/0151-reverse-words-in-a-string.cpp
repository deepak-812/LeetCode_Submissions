class Solution {
public:
    string reverseWords(string s) { // T.C. O(n) && A.S. O(n)
        s+=" ";
        stack<string> stk;
        int i=0,len=s.length();
        string tmp="";
        for(;i<len;i++){
            if(s[i]==' '){
                while(i<len && s[i]==' ')i++;
                if(tmp.size())stk.push(tmp);
                tmp="";
                i--;
            }
            else{
                tmp+=s[i];
            }
        }
        string res="";
        while(!stk.empty()){
            res+=stk.top();
            res+=" ";
            stk.pop();
        }
        res.pop_back();
        return res;
    }
};