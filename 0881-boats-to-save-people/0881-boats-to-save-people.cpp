class Solution { // T.C. O(n+log(n)) 
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        int i=0 , j=arr.size()-1;
        sort(arr.begin(),arr.end());
        int ans=0;
        while(i<=j){
            if(arr[i]+arr[j]<=limit){
                i++;
            }
            ans++;
            j--;
        }
        return ans;
    }
};