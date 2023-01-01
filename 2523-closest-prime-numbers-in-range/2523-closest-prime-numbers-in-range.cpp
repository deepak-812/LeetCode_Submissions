class Solution {
public:
    bool is_prime[1000001];
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2,-1);
        sieve();
        int gap=INT_MAX;
        int k=left;
        while(!is_prime[k])k++;
        for(int i=k+1;i<=right;i++){
            if(is_prime[i]){
                if(abs(i-k)<gap){
                    gap=abs(i-k);
                    ans[0]=k;
                    ans[1]=i;
               }
               k=i;
            }
        }
        return ans;
    }
    
    void sieve() //we use hashing
    {
        int maxN=1000000;

        for(int i=0;i<=maxN;i++)is_prime[i]=1; // fill sieve with allvalue true
        is_prime[0]=is_prime[1]=0;
        for(int i=2;i*i<=maxN;i++) //to traverse whole sieve
        {
            if(is_prime[i]){
                for(int j=i*i;j<=maxN;j+=i) //make all multiples of i composite starting from it's sqaure
                     is_prime[j]=0;
                 }
             }
    }
};