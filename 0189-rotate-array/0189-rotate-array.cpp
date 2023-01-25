class Solution {
public:
    void rotate(vector<int>& nums, int k) { // T.C. O(n) A.S. O(n)
        int len=nums.size();
        if(len==0){
            return;
        }
        k=k%len;
        int x=k;
        if(k==0){
            return;
        }
        stack<int> stk;
        int n=len-1;
        while(k--){
            stk.push(nums[n]);
            n--;
        }
        vector<int> arr;
        while(!stk.empty()){
            arr.push_back(stk.top());
            stk.pop();
        }
        for(int i=0;i<len-x;i++){
            arr.push_back(nums[i]);
        }
        nums=arr;
        return;
    }
};