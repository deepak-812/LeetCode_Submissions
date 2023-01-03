//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    long long atoi(string str) {
        //Your code here
        long long ans=0;
        int i=0;
        for(int i=0;i<str.length();i++){
            if(i==0 && str[i]=='-'){
                continue;
            }
            if(str[i]<'0' || str[i]>'9'){
                return -1;
            }
            ans=ans*10+(str[i]-'0');
        }
        if(str[0]=='-'){
            ans=ans*(-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends