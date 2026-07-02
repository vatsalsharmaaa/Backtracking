// class Solution {
// public:
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {

//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

//         priority_queue< vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

//         dist[0][0] = grid[0][0];
//         pq.push({dist[0][0], 0, 0});

//         vector<pair<int,int>> dir = {
//             {1,0}, {-1,0}, {0,1}, {0,-1}
//         };

//         while (!pq.empty()) {

//             auto cur = pq.top();
//             pq.pop();

//             int cost = cur[0];
//             int x = cur[1];
//             int y = cur[2];

//             if (cost > dist[x][y]) continue;

//             for (auto [dx, dy] : dir) {

//                 int nx = x + dx;
//                 int ny = y + dy;

//                 if (nx < 0 || ny < 0 || nx >= m || ny >= n)
//                     continue;

//                 int newCost = cost + grid[nx][ny];

//                 if (newCost < dist[nx][ny]) {

//                     dist[nx][ny] = newCost;
//                     pq.push({newCost, nx, ny});
//                 }
//             }
//         }

//         return dist[m-1][n-1] < health;
//     }
// };












class Solution {
public:

    vector<vector<int>>dirs={{0,1},{0,-1},{-1,0},{1,0}};
    typedef pair<int,pair<int,int>>p;

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>res (n,vector<int>(m,INT_MAX));

        priority_queue<p,vector<p> ,greater<p>>pq;
        res[0][0] = grid[0][0];
        pq.push({res[0][0], {0,0}}); //dist,{src,dst}

        while(!pq.empty()){
            int dist=pq.top().first;
            auto cord= pq.top().second;

            int x=cord.first;
            int y=cord.second;

            pq.pop();

            for(auto dir:dirs){
                int ni= x+ dir[0];
                int nj= y+ dir[1];

                if(ni<0||nj<0||ni>n-1||nj>m-1) continue;

                int new_dist= grid[ni][nj] + dist;
                if(res[ni][nj]> grid[ni][nj]+dist){
                    res[ni][nj]= grid[ni][nj] +dist;
                    pq.push({res[ni][nj] ,{ni,nj}});
                }

            }
        }


        return res[n-1][m-1]<health;


    }
};