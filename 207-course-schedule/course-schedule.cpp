class Solution {
public:
    bool solve(vector<vector<int>>&adj,vector<int>&indegree,int v){
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int p=q.front();
            q.pop();
            count++;

            for(auto x: adj[p]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        return count==v;
    }
    bool canFinish(int v, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<int>indegree(v,0);
        vector<vector<int>>adj(v);
        for(auto x: pre){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        return solve(adj,indegree,v);
        
    }
};