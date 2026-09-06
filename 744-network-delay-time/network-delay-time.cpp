class Solution {
public:
    typedef pair<int,int>p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>>adj(n+1);
        for(auto x: times){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});

        }
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<int>dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k]=0;
        
        while(!pq.empty()){
            int node=pq.top().second;
            int weight= pq.top().first;
            pq.pop();

            for(auto &it: adj[node]){
                int node_= it.first;
                int weight_=it.second;

                if(weight+weight_<dist[node_]){
                    dist[node_]= weight+weight_;
                
                    pq.push({weight+weight_,node_});
                }
            }
        }
          int time = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX)
                return -1;

            time = max(time, dist[i]);
        }

        return time;
    }
};