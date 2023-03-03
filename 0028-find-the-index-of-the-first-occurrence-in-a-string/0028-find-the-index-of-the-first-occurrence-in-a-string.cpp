class Solution {
public:
    int strStr(string haystack, string needle) {
        int ind=-1;
        int len1=haystack.length();
        int len2=needle.length();
        int j=0;

        if(!len2)return 0;

        for(int i=0;i<len1;i++)
        {
          if(haystack[i]==needle[j])
          {
            int t=i;
            while((j<len2 && i<len1) && haystack[++i]==needle[++j]);
            if(j==len2)
            {
              ind=t;
              break;
            }
            else j=0 , i=t;
          }
        }
      return ind;
    }
};