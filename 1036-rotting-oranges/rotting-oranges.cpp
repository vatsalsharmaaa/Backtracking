class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    typedef pair<int,int> p;

    int n, m;

    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;

        n = grid.size();
        m = grid[0].size();

        queue<p> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool rotten = false;

            while (size--) {
                auto it = q.front();
                q.pop();

                int i = it.first;
                int j = it.second;

                for (auto dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if (ni >= 0 && nj >= 0 &&
                        ni < n && nj < m &&
                        grid[ni][nj] == 1) {

                        grid[ni][nj] = 2;
                        fresh--;
                        rotten = true;

                        q.push({ni, nj});
                    }
                }
            }

            if (rotten)
                time++;
        }

        if (fresh > 0)
            return -1;

        return time;
    }
};