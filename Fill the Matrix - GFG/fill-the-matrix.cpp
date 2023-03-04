//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int y, int x){    
        // code here
        // if(n==1 && m==1 && x==1 && y==1)return 0;
        vector<vector<bool>> vis(n+1,vector<bool> (m+1,false));
        int iters=-1;
        vector<int> dx={-1,0,1,0} , dy={0,-1,0,1};
        queue<pair<int,int>> q;
        q.push({y,x});
        vis[y][x]=true;
        while(!q.empty()){
            int sze=q.size();
            iters++;
            for(int i=0;i<sze;i++){
                y=q.front().first;
                x=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int r=y+dy[k],c=x+dx[k];
                    if(r>=1 && c>=1 && r<=n && c<=m && !vis[r][c]){
                        vis[r][c]=true;
                        q.push({r,c});
                    }
                }
            }
        }
        return iters;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends