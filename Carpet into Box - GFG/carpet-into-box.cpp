//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        //code here
        int len=a,wid=b,step=0;
        while(len>c || wid>d){
            if(len>c){
                len/=2;
                step++;
            }
            if(wid>d){
                wid/=2;
                step++;
            }
        }
        len=b,wid=a;
        int prevStep=step;
        step=0;
        while(len>c || wid>d){
            if(len>c){
                len/=2;
                step++;
            }
            if(wid>d){
                wid/=2;
                step++;
            }
        }
        return min(step,prevStep);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends