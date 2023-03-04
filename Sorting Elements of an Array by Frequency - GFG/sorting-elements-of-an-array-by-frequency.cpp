//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    static bool cmp(pair<int,int> p,pair<int,int> q){
        if(p.first!=q.first){
            return p.first>q.first;
        }
        return p.second<q.second;
    }
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n){
        //Your code here
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto it:freq){
            int ff=it.first;
            int ss=it.second;
            v.push_back({ss,ff});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(auto it:v){
            int freq=it.first;
            int item=it.second;
            while(freq>0){
                ans.push_back(item);
                freq--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends