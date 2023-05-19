class Solution {
public:
    bool vis[101];
    bool col[101];
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(i,0,graph)){
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(int node,int c,vector<vector<int>>& graph){
        vis[node]=true;
        col[node]=c;
        for(auto child:graph[node]){
            if(!vis[child]){
                if(dfs(child,c^1,graph)==false){
                    return false;
                }
            }
            else if(col[child]==col[node]){
                return false;
            }
        }
        return true;
    }

};