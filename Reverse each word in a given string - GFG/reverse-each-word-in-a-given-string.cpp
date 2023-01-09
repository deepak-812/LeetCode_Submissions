//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        s+='.';
        string str="";
        stack<char> stk;
        for(auto c:s){
            if(c=='.'){
                while(stk.empty()==false){
                    str+=stk.top();
                    stk.pop();
                }
                str+='.';
            }
            else{
                stk.push(c);
            }
        }
        str.pop_back();
        return str;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends