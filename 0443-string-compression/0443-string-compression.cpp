class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        if(!chars.size())return 0;
        chars.push_back(' ');
        int freq=1;
        char c=chars[0];
        ans.push_back(chars[0]);
        for(int i=1;i<chars.size();i++){
            if(c!=chars[i]){
                if(freq>1){
                    if(freq<10){
                        ans.push_back(freq+'0');
                    }
                    else{
                        stack<char> stk;
                        while(freq>0){
                            int rem=freq%10;
                            stk.push(rem+'0');
                            freq/=10;
                        }
                        while(!stk.empty()){
                            ans.push_back(stk.top());
                            stk.pop();
                        }
                    }
                }
                c=chars[i];
                freq=0;
                ans.push_back(c);
            }
            freq++;
        }
        ans.pop_back();
        chars=ans;
        return ans.size();
    }
};