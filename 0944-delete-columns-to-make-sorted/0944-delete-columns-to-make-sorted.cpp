class Solution {
public:
    int minDeletionSize(vector<string>& strs) { // T.C. O(n^2) and A.S. O(2n)
        int ans=0;
        for(int i=0;i<strs[0].size();i++){
            string s="";
            for(int j=0;j<strs.size();j++){
                s+=strs[j][i];
            }
            string tmp=s;
            sort(tmp.begin(),tmp.end());
            if(tmp!=s){
                ans++;
            }
        }
        return ans;
    }
};