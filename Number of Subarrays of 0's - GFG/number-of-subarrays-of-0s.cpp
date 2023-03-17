//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long ans=0;
    int l=0,r=0;
    while(r<n){
        if(arr[r]==0){
            l=r;
            while(r<n && arr[r]==0)r++;
            r--;
            long long m=(r-l)+1;
            ans+=(m*(m+1))/2;
        }
        r++;
    }
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends