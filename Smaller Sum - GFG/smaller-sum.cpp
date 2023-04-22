//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int> as(arr.begin(),arr.end());
        vector<long long> ans(n,0);
        vector<long long> sum(n,0);
        long long sumVal=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
             sum[i]=sumVal;
             sumVal+=arr[i];
        }
        for(int i=0;i<n;i++){
            int ind=lower_bound(arr.begin(),arr.end(),as[i])-arr.begin();
            ans[i]=sum[ind];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends