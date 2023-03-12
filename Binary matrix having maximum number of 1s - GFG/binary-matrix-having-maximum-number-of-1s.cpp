//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int cnt=0;
        vector<int> ans(2,0);
        for(int i=0;i<N;i++){
            for(int j=N-1;j>=0;j--){
                if(!mat[i][j]){
                    break;
                }
                while(j>=0 && mat[i][j]){
                    cnt++ , j--;
                }
                if(cnt>ans[1]){
                    ans[1]=cnt;
                    ans[0]=i;
                }
                cnt=0;
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends