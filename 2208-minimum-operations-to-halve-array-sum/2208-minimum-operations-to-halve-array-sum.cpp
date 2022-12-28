class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        priority_queue<double> pq;
        for(auto it:nums){
            sum+=it;
            pq.push(it);
        }
        sum/=2;
        int ans=0;
        while(sum>0){
            sum-=pq.top()/2;
            pq.push(pq.top()/2);
            pq.pop();
            ans++;
        }
        return ans;
    }
};