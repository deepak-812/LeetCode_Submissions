//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        string str="";
        stack<char> stk;
        if(!s.length()){
            return str;
        }
        for(auto c:s){
            bool flag=true;
            while(!stk.empty() && stk.top()==c){
                stk.pop();
                flag=false;
            }
            if(flag)
            stk.push(c);
        }
        while(!stk.empty()){
            str+=stk.top();
            stk.pop();
        }
        reverse(str.begin(),str.end());
        if(str.length()==0){
            str="Empty String";
        }
        return str;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends