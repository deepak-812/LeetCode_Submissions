//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    vector<int> freq(26,0);
	    vector<int> freq2(26,0);
	     for(auto c:pat){
	         freq[c-'a']++;
	     }
	     int ans=0,l=0,r=0,len=txt.length();
	     while(r<pat.length()-1){
	         freq2[txt[r]-'a']++ , r++;
	     }
	     while(r<txt.length()){
	         bool flag=true;
	         freq2[txt[r]-'a']++;
	         for(int i=0;i<26;i++){
	             if(freq2[i]!=freq[i]){
	                 flag=false;
	             }
	         }
	         if(flag)ans++;
	         freq2[txt[l]-'a']--;
	         l++ , r++;
	     }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends