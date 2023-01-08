//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/* // T.C. O(n) A.S. O(1)
class Solution{
    int minEle;
    stack<int> ax;
    stack<int> s;
    public:
    
    //  returns min element from stack
       int getMin(){
           if(ax.size()==0){
               return -1;
           }
           return ax.top();
           //Write your code here
       }
       
    //   /*returns poped element from stack
       int pop(){
           if(s.size()==0){
               return -1;
           }
           if(s.top()==ax.top()){
               ax.pop();
           }
           int val=s.top();
           s.pop();
           return val;
           //Write your code here
       }
       
    //   /*push element x into the stack
       void push(int x){
           if(!ax.size() || x<=ax.top()){
               ax.push(x);
           }
           s.push(x);
           //Write your code here
       }
};
*/

// T.C. O(n) and A.S. O(1) Best Solution

class Solution{
    int min;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.size()==0){
               return -1;
           }
           return min;
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.size()==0){
               return -1;
           }
           int val;
           if(s.top()<=0){
               min=min+(abs(s.top()));
               val=min+s.top();
           }
           else{
               val=s.top();
           }
           s.pop();
           return val;
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(!s.size()){
               min=x;
               s.push(x);
               return;
           }
           if(x<=min){
               s.push(x-min);
               min=x;
           }
           else{
               s.push(x);
           }
           //Write your code here
       }
};





//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends