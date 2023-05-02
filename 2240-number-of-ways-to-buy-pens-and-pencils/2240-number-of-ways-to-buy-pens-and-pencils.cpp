class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        int pen=total/cost1;
        int pencils=total/cost2;
        while(pen>=0){
             ans+=((total-(pen*cost1))/cost2+1);
             pen--;
        }
        return ans;
    }
};