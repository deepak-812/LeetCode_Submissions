class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> missingElem;
        int n=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=n){
                while(arr[i]!=n)missingElem.push_back(n) , n++;
                n-- , i--;
            }
            n++;
        }
        if(missingElem.size()<k){
            while(missingElem.size()<k){
                missingElem.push_back(n) , n++;
            }
        }
        return missingElem[k-1];
    }
};