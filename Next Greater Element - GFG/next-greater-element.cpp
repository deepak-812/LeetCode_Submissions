//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long> ans(arr.size(),-1);
        stack<long long> stk;
        if(!arr.size()){
            return ans;
        }
        for(int i=arr.size()-1;i>=0;i--){
            while(!stk.empty() && stk.top()<=arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i]=stk.top();
            }
            stk.emplace(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends