class Solution {
public:
    typedef pair<double,int> p; // {probability, node}
    
    double maxProbability(int n, vector<vector<int>>& edges, 
                          vector<double>& succProb, 
                          int start_node, int end_node) {
        
        vector<vector<pair<int,double>>> adj(n);
        
        // Build graph (undirected)
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        
        // Max probability array
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        
        // Max heap
        priority_queue<p> pq;
        pq.push({1.0, start_node});
        
        while(!pq.empty()){
            auto [prob, node] = pq.top();
            pq.pop();
            
            if(node == end_node)
                return prob;
            
            for(auto &it : adj[node]){
                int nextNode = it.first;
                double edgeProb = it.second;
                
                double newProb = prob * edgeProb;
                
                if(newProb > dist[nextNode]){
                    dist[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }
        
        return 0.0;
    }
};