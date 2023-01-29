//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        // code here
        stack<int> stk;
        stk.push(-1);
        int ans=0;
        for(int i=0;i<s.length();i++){
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

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends