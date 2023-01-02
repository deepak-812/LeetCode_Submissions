//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution { //Two pointer approach
  public:
    int canReach(int arr[], int n) {
        // code here
        int j=0,i;
        for(i=0;i<n && j>=i;i++){
            j=max(j,i+arr[i]);
        }
        return i==n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends