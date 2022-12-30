class Solution {
public:
    int n;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size()-1;
        vector<vector<int>> path;
        vector<int> as;
        dfs(graph,0,as,path);
        return path;
    }
    void dfs(vector<vector<int>>& adj,int ind,vector<int> as,vector<vector<int>>&path){
        as.push_back(ind);
        if(ind==n){
            path.push_back(as);
            return;
        }
        for(auto child:adj[ind]){
            dfs(adj,child,as,path);
        }
    }
};