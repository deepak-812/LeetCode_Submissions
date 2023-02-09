class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        bool flag=false;
        int required=t.length();
        if(!required || !s.length() || s.length()<t.length())return "";
        vector<int> requiredFreq(256,0);
        vector<int> currMap(256,0);
        for(auto c:t){
            requiredFreq[c]++;
        }
        int start=0,end=0,minLen=INT_MAX,len=required,left=0,lastInd=0;
        while(end<=s.length() && start<s.length()){
            if(len){
                if(end==s.length())break;
                if(requiredFreq[s[end]]>currMap[s[end]])len--;
                currMap[s[end]]++;
                end++;
            }
            else{
                flag=true;
                int strLen=end-start+1;
                if(strLen<minLen){
                    left=start;
                    minLen=strLen;
                    lastInd=end-1;
                }
                if(currMap[s[start]]==requiredFreq[s[start]])len++;
                currMap[s[start]]--;
                start++;
            }
        }
        if(!flag)return "";
        ans=s.substr(left,lastInd-left+1);
        return ans;
    }
};