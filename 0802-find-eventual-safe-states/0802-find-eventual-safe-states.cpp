class Solution { 
private:
    bool dfs(int node,vector<bool> &vis,vector<bool> &pathVis,vector<bool> &check,vector<int> adj[]){
        vis[node]=true , pathVis[node]=true;
        for(auto child:adj[node]){
            if(!vis[child]){
                if(dfs(child,vis,pathVis,check,adj))return true;
            }
            else if(pathVis[child]){
                return true;
            }
        }
        pathVis[node]=false , check[node]=true;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // adj.resize(graph.size());
        vector<int> adj[graph.size()];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<bool> check(graph.size(),false);
        vector<bool> pathVis(graph.size(),false) , vis(graph.size(),false);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,check,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(check[i])ans.push_back(i);
        }
        return ans;
    }
};