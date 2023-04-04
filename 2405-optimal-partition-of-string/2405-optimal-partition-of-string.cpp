class Solution {
public:
    int partitionString(string s) {
        int res=1, i=0, j=0;
        while(j < s.length()){
            if(s.substr(i,j-i).find(s[j])==string::npos)
                j++;
            else{
                res++;
                i=j;
            }
        }
        return res;
    }
};