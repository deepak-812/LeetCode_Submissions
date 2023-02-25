class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &nums) {
        int n=numCourses;
        vector<int> adj[n];
        for(int i=0;i<nums.size();i++){
            adj[nums[i][0]].push_back(nums[i][1]);
        }
        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        int cnt=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            cnt++;
            q.pop();
            for(auto child:adj[node]){
                inDegree[child]--;
                if(inDegree[child]==0){
                    q.push(child);
                }
            }
        }
        return cnt==n;
    }
};