class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int n, m;
    typedef pair<int, int> p;
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int fresh = 0;
        queue<p> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if (fresh == 0) {
            return 0;
        }
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            int temp = 0;
            while (size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (auto dir : dirs) {

                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj <m &&
                        grid[ni][nj] == 1) {
                        temp++;
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                    }
                }
                
            }
            if (temp > 0)
                    time++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    time = 0;
                    break;
                }
            }
        }
        return (time == 0) ? -1 : time;
    }
};