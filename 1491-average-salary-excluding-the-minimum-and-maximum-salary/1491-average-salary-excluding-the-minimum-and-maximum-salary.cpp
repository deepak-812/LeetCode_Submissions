class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int n=salary.size();
        double sum=0;
        for(int i=1;i<n-1;i++){
            sum+=salary[i];
        }
        sum/=n-2;
        double tmp=long(sum)+(1L*(100000*(sum-long(sum))))/100000;
        return tmp;
    }
};