//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int> freq(26,0);
        if(!s.length()){
            return 0;
        }
        for(auto c:s){
            freq[c-'a']++;
        }
        int ans;
        ans=min(freq['b'-'a'],min(freq[0],freq['l'-'a']/2));
        ans=min(ans,min(freq['o'-'a']/2,freq['n'-'a']));
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends