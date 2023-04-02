class Solution {   //o(nlog(n))
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      sort(potions.begin(),potions.end());
      vector<int> res;
      int n=potions.size();
      for(auto elem:spells)
      {
        int hi=n-1 , lo=0 , mid;
        while(hi-lo>1)
        {
          mid=(hi+lo)/2;
          if(1LL * elem * potions[mid] < success)lo=mid+1;
          else hi=mid;
        }
        int tmp;
        if(success <= 1LL * elem * potions[lo])tmp=lo;
        else if(success <= 1LL * elem * potions[hi])tmp=hi;
        else tmp=n;
        int ans=n-tmp;
        res.emplace_back(ans);
      }
      return res;
    }
};