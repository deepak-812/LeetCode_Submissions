//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) { // T.C. O(4n) and A.S. O(1)
        // code here
        // Hint use the idea to extract two missing numbers from array of size n-2
        int x=0,y=0;
        for(int i=1;i<=n;i++){
            x^=i;
        }
        for(int i=0;i<n;i++){
            x^=arr[i];
        }
        int lastSetBit= x & ~(x-1);
        x=0;
        for(int i=0;i<n;i++){
            if(arr[i] & lastSetBit){
                x^=arr[i];
            }
            else{
                y^=arr[i];
            }
        }
        for(int i=1;i<=n;i++){
           if(i & lastSetBit){
               x^=i;
           }
           else{
               y^=i;
           }
       }
       int *ans=new int[2];
       bool flag=false;
       for(int i=0;i<n;i++){
           if(arr[i]==y){
               flag=true;
               break;
           }
       }
       if(flag){
           ans[0]=y;
           ans[1]=x;
       }
       else{
           ans[0]=x;
           ans[1]=y;
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends