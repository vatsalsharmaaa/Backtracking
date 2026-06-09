class Solution {
public:

    int dfs(int curr,int parent ,unordered_map<int ,vector<int>>&adj, vector<bool>& hasApple ){
        int time=0;
        for(auto neigh:adj[curr]){
            if(neigh==parent) continue;
            int totaltime=dfs(neigh,curr,adj,hasApple);
            if(totaltime>0 || hasApple[neigh]==true){
                time+=totaltime+2;
            }

        }
        return time ;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int ,vector<int>>adj;
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0,-1,adj,hasApple);
    }
};