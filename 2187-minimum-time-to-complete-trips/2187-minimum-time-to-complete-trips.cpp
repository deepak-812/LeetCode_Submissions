class Solution {
public:
    bool isValid(vector<int> &time,long long int mid,int total){
        long long int cnt=0;
        for(auto it:time){
            cnt+=mid/it;
        }
        return cnt>=total;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans;
        sort(time.begin(),time.end());
        long long int lft=1 , rght=1LL*totalTrips*time[0],mid;
        while(lft<=rght){
            mid=(rght+lft)/2;
            if(isValid(time,mid,totalTrips)){\
                ans=mid;
                rght=mid-1;
            }
            else{
                lft=mid+1;
            }
        }
        return ans;
    }
};