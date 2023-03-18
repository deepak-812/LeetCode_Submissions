//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int num=1,l=0,r=0,i=0;
           int ans=0;
           while(r<n){
               if(arr[r]==0){
                   l=r+1 , i=r+1 , num=1;
               }
               else{
                   if(arr[r]<0){
                       num*=-1;
                       if(num>0){
                           l=i;
                       }
                       else{
                           i=l;
                           l=r+1;
                       }
                   }
                   ans=max(r-l+1,ans);
               }
               r++;
           }
           num=1,l=n-1,r=n-1,i=n-1;
           while(l>=0){
               if(arr[l]==0){
                   r=l-1 , i=l-1 , num=1;
               }
               else{
                   if(arr[l]<0){
                       num*=-1;
                       if(num>0){
                           r=i;
                       }
                       else{
                           i=r;
                           r=l-1;
                       }
                   }
                   ans=max(r-l+1,ans);
               }
               l--;
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends