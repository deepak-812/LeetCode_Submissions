class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) { // T.C. O(pow(2,n)+log(n)) A.S. O(3*n)
        vector<int> v;
        set<vector<int>> st;
        solve(nums,v,0,st);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
    void solve(vector<int>& nums,vector<int> &v,int ind,set<vector<int>>& st){
        if(ind==nums.size()){
            if(v.size()>1){
                vector<int> tmp(v.begin(),v.end());
                sort(tmp.begin(),tmp.end());
                if(tmp==v)
                    st.emplace(v);
            }
            return;
        }
        v.push_back(nums[ind]);
        solve(nums,v,ind+1,st);
        v.pop_back();   
        solve(nums,v,ind+1,st);
    }
};