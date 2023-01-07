//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int s)
    {
        
        // your code here
        unordered_map<int,int> mp;
        for(int i=0;i<s;i++){
            mp[a[i]]++;
        }
        int ans=-1;
        int maxC=0;
        for(auto it:mp){
            int n=it.second;
            if(n>maxC){
                ans=it.first;
                maxC=it.second;
            }
        }
        return maxC>s/2?ans:-1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends