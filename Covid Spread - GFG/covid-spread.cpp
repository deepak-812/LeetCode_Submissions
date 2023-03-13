//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int m,n;
    bool isValid(int r,int c,vector<vector<int>> &grid){
        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]==2 || grid[r][c]==0)return false;
        return true;
    }
public:
    int helpaterp(vector<vector<int>> hospital){
        //code here
        m=hospital.size() , n=hospital[0].size();
        vector<int> dx={-1,0,1,0} , dy={0,-1,0,1};
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(hospital[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int sze=q.size();
            for(int i=0;i<sze;i++){
                int y=q.front().first.first;
                int x=q.front().first.second;
                int d=q.front().second;
                ans=d;
                for(int i=0;i<4;i++){
                    if(isValid(y+dy[i],x+dx[i],hospital)){
                        hospital[y+dy[i]][x+dx[i]]=2;
                        q.push({{y+dy[i],x+dx[i]},d+1});
                    }
                }
                q.pop();
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(hospital[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends