//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(j>0){
	                arr[i][j]=arr[i][j-1]+arr[i][j];
	            }
	        }
	    }
	    int maxR=0;
	    int r=-1;
	    for(int i=0;i<n;i++){
	        if(arr[i][m-1]>maxR){
	            maxR=arr[i][m-1];
	            r=i;
	        }
	    }
	    return r;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends