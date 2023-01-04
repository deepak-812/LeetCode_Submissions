//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int k) {
        // code here
        int ans=0;
        int cnt=0;
        int j=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                cnt++;
            }
            while(cnt>k){
                j++;
                if(arr[j]==0){
                    cnt--;
                }
            }
            int len=i-j;
            ans=max(len,ans);
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends