//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int> > subsets(vector<int>& a)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> nums;
        solve(a,ans,nums);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void solve(vector<int> &a,vector<vector<int>> &ans,vector<int> &nums,int ind=0){
        if(ind==a.size()){
            ans.push_back(nums);
            return;
        }
        solve(a,ans,nums,ind+1);
        nums.push_back(a[ind]);
        solve(a,ans,nums,ind+1);
        nums.pop_back();
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends