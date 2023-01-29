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
                st.emplace(v);
            }
            return;
        }
        if(!v.size() || (nums[ind]>=v.back())){
            v.push_back(nums[ind]);
            solve(nums,v,ind+1,st);
            v.pop_back();    
        }  
        solve(nums,v,ind+1,st);
    }
};