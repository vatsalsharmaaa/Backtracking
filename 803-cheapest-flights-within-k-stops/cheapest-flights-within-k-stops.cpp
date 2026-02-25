class Solution {
public:
    typedef pair<int,int> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>dist(n,INT_MAX);
        vector<vector<p>>adj(n);
        for(auto v:flights){
            int a= v[0];
            int b=v[1];
            int cost=v[2];

            adj[a].push_back({b,cost});
        }
        queue<p>q;
        q.push({src,0});
        dist[src]=0;
        int steps=0;
        while(!q.empty()&&steps<=k){
            int size= q.size();

            while(size--){
                int u=q.front().first;
                int d=q.front().second;
                q.pop();
                for(auto it:adj[u]){
                    int node=it.first;
                    int w=it.second;
                    if(dist[node]>d+w){
                        dist[node]=d+w;
                        q.push({node,d+w});
                    }
                }
            }
            steps++;
        }

        return dist[dst]==INT_MAX? -1:dist[dst];
    }
};