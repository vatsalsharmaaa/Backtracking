// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
        
//         // If start or end is blocked
//         if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
//         vector<vector<bool>> visited(n, vector<bool>(n, false));
        
//         queue<pair<int,int>> q;
//         q.push({0,0});
//         visited[0][0] = true;
        
//         int pathLength = 1;
        
//         // 8 possible directions
//         vector<pair<int,int>> dirs = {
//             {1,0},{-1,0},{0,1},{0,-1},
//             {1,1},{1,-1},{-1,1},{-1,-1}
//         };
        
//         while(!q.empty()){
//             int size = q.size();
//             while(size--){
//                 auto [x, y] = q.front();
//                 q.pop();
                
//                 // If reached bottom right
//                 if(x == n-1 && y == n-1) return pathLength;
                
//                 for(auto &d : dirs){
//                     int nx = x + d.first;
//                     int ny = y + d.second;
                    
//                     if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
//                        !visited[nx][ny] && grid[nx][ny] == 0){
//                         visited[nx][ny] = true;
//                         q.push({nx, ny});
//                     }
//                 }
//             }
//             pathLength++;
//         }
        
//         return -1;
//     }
// };




class Solution {
public:
    typedef pair<int,pair<int,int>> p;

    vector<vector<int>> dirs = {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},           {0,1},
        {1,-1},  {1,0},   {1,1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<p, vector<p>, greater<p>> pq;

        dist[0][0] = 1;
        pq.push({1, {0,0}});

        while(!pq.empty()) {

            int weight = pq.top().first;
            auto node = pq.top().second;

            int nodex = node.first;
            int nodey = node.second;

            pq.pop();

            if(weight > dist[nodex][nodey])
                continue;

            for(auto &dir : dirs) {

                int nodex_ = nodex + dir[0];
                int nodey_ = nodey + dir[1];

                if(nodex_ >= 0 && nodex_ < n &&
                   nodey_ >= 0 && nodey_ < m &&
                   grid[nodex_][nodey_] == 0) {

                    int new_weight = 1;

                    if(weight + new_weight < dist[nodex_][nodey_]) {

                        dist[nodex_][nodey_] = weight + new_weight;

                        pq.push({
                            weight + new_weight,
                            {nodex_, nodey_}
                        });
                    }
                }
            }
        }

        if(dist[n-1][m-1] == INT_MAX)
            return -1;

        return dist[n-1][m-1];
    }
};















