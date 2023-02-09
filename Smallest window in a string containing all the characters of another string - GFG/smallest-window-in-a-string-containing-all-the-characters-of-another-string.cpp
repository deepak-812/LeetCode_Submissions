//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t){
        // Your code here
        string ans="";
        int required=t.length();
        if(!required || !s.length() || s.length()<t.length())return "-1";
        vector<int> requiredFreq(128,0);
        vector<int> currMap(128,0);
        for(auto c:t){
            requiredFreq[c-'a']++;
        }
        int start=0,end=0,minLen=INT_MAX,len=required,left=0;
        while(end<=s.length() && start<s.length()){
            if(len){
                if(end==s.length())break;
                if(requiredFreq[s[end]-'a']>currMap[s[end]-'a'])len--;
                currMap[s[end]-'a']++;
                end++;
            }
            else{
                int strLen=end-start+1;
                if(strLen<minLen){
                    left=start;
                    minLen=strLen;
                }
                if(currMap[s[start]-'a']==requiredFreq[s[start]-'a'])len++;
                currMap[s[start]-'a']--;
                start++;
            }
        }
        if(minLen==INT_MAX)return "-1";
        ans=s.substr(left,minLen-1);
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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends