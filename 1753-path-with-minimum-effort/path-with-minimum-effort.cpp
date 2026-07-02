class Solution {
public:
    vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
    typedef pair<int,pair<int,int>>p;

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m= heights[0].size();
        vector<vector<int>>res(n,vector<int>(m, INT_MAX));

        priority_queue<p,vector<p>,greater<p>>pq;
       res[0][0] = 0;
       pq.push({0, {0,0}});
        while(!pq.empty()){
            int dist= pq.top().first;
            auto index= pq.top().second;

            int i=index.first;
            int j=index.second;
            pq.pop();

            for(auto dir:dirs){
                int ni= i+dir[0];
                int nj= j+dir[1];

                if(ni<0||nj<0||ni>n-1||nj>m-1) continue;
                int absdist= abs(heights[i][j]- heights[ni][nj]);
                int maxdiff= max(dist, absdist);

                if(res[ni][nj]>maxdiff){
                    res[ni][nj]=maxdiff;
                     pq.push({res[ni][nj],{ni,nj}});
                }
               
            }
        }
            return res[n-1][m-1];
     }
};