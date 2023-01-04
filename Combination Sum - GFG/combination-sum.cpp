//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &a, int b) {
        // Your code here
        set<vector<int>> st;
        sort(a.begin(),a.end());
        vector<int> nums;
        solve(a,b,0,nums,st);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
    void solve(vector<int>& a,int b,int ind,vector<int> &nums,set<vector<int>>&st){
        if(b<0){
            return;
        }
        if(ind==a.size()){
            if(b==0){
                st.emplace(nums);
            }
            return;
        }
        if(a[ind]<=b){
            nums.push_back(a[ind]);
            solve(a,b-a[ind],ind,nums,st);
            if(ind<a.size() && nums[nums.size()-1]==a[ind])
            {
             while(ind<a.size() && nums[nums.size()-1]==a[ind])ind++;
             ind--;
            }
            nums.pop_back();
        }
        solve(a,b,ind+1,nums,st);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends