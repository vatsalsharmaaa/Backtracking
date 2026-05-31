class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int val) {
        idx++;
        while (idx <= n) {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++;
        int res = 0;

        while (idx > 0) {
            res = max(res, bit[idx]);
            idx -= idx & -idx;
        }

        return res;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAXX = 50000;

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(MAXX);

        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        Fenwick bit(MAXX + 1);

        int prv = *obstacles.begin();
        for (auto it = next(obstacles.begin()); it != obstacles.end(); ++it) {
            bit.update(*it, *it - prv);
            prv = *it;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                --it;

                int pred = *it;

                int bestGap = max(bit.query(x), x - pred);

                ans.push_back(bestGap >= sz);
            } else {
                int pos = q[1];

                auto it = obstacles.find(pos);

                auto L = std::prev(it);
                auto R = std::next(it);

                bit.update(*R, *R - *L);

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};