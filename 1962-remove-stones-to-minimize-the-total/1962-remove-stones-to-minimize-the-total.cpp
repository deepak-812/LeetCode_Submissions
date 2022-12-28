/*
class Solution { // Gets TLE T.C. O(nlog(n)) and A.S. O(1)
public:
    int minStoneSum(vector<int>& piles, int k) {
        while(k--){
            sort(piles.begin(),piles.end(),greater<int>());
            piles[0]-=floor(piles[0]/2);
        }
        int sum=0;
        for(auto it:piles){
            sum+=it;
        }
        return sum;
    }
};
*/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum=0;
        for(auto it:piles){
            pq.push(it);
            sum+=it;
        }
        while(k--){
            pq.push(pq.top()-floor(pq.top()/2));
            sum-=floor(pq.top()/2);
            pq.pop();
        }
        return sum;
    }
};