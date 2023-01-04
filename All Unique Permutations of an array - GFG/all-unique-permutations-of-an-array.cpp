//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code here
        set<vector<int>> st;
        solve(arr,st,0);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
    void solve(vector<int>& arr,set<vector<int>> &st,int ind){
        if(ind==arr.size()-1){
            st.emplace(arr);
        }
        for(int j=ind;j<arr.size();j++){
            swap(arr[ind],arr[j]);
            solve(arr,st,ind+1);
            swap(arr[ind],arr[j]);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends