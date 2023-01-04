//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    set<string> st;
		    solve(s,st,0);
		    vector<string> ans(st.begin(),st.end());
		    return ans;
		}
		void solve(string &s,set<string> &st,int ind){
		    if(ind==s.length()-1){
		        st.emplace(s);
		        return;
		    }
		    for(int j=ind;j<s.size();j++){
		        swap(s[ind],s[j]);
		        solve(s,st,ind+1);
		        swap(s[ind],s[j]);
		    }
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends