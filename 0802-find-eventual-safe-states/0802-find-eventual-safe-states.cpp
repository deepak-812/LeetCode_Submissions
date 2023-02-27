class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // using bfs Using Outdegree
        // for outdegree reverse the link and find indegree
        vector<int> adj[graph.size()];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        vector<int> outdegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto it:adj[i]){
                outdegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        vector<bool> check(graph.size(),false);
        while(!q.empty()){
            int node=q.front();
            check[node]=true;
            q.pop();
            for(auto child:adj[node]){
                outdegree[child]--;
                if(!outdegree[child]){
                    q.push(child);
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(check[i])ans.push_back(i);
        }
        return ans;
    }
};