//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        vector<bool> bitsN(32,false);
        int cnt=0;
        while(n>0){
            if(n&1)bitsN[cnt]=true;
            cnt++ , n=n>>1;
        }
        int r=cnt-1,l;
        l=r;
        for(;l>=0;l--){
            if(bitsN[l]==false){
                r=l-1;
            }
            else if(r-l+1==3){
                bitsN[l]=false;
                l++;
                r=l-1;
            }
        }
        int ans=0;
        for(int i=0;i<cnt;i++){
            ans+=bitsN[i]*pow(2,i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends