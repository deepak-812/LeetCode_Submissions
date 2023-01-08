class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(auto it:nums){
            pq.push(it);
        }
        long long ans=0;
        while(k-- && pq.empty()==false){
            ans+=pq.top();
            if(pq.top()%3==0){
                pq.push((pq.top())/3);
            }
            else
                pq.push((pq.top())/3+1);
            pq.pop();
        }
        return ans;
    }
};