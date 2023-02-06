//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> ans(2,-1);
        if(!s){
            return {-1};
        }
        int l=0,r=0;
        long long currSum=0;
        while(r<n){
            currSum+=arr[r];
            if(currSum>s){
                while(l<=r && currSum>s){
                    currSum-=arr[l] , l++;
                }
            }
            if(currSum==s){
                ans[0]=l+1;
                ans[1]=r+1;
                break;
            }
            r++;
        }
        if(ans[0]==-1)ans.pop_back();
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends