class Solution {
public:
    
    long long query(long long A,
                    vector<pair<int,int>>& rides,
                    vector<int>& prefMinDur,
                    vector<long long>& suffMinFinish) {
        
        int n = rides.size();

        int idx = upper_bound(
            rides.begin(), rides.end(),
            make_pair((int)A, INT_MAX)
        ) - rides.begin() - 1;

        long long ans = LLONG_MAX;

        if (idx >= 0)
            ans = min(ans, A + prefMinDur[idx]);

        if (idx + 1 < n)
            ans = min(ans, suffMinFinish[idx + 1]);

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int,int>> water, land;

        for (int i = 0; i < m; i++)
            water.push_back({waterStartTime[i], waterDuration[i]});

        for (int i = 0; i < n; i++)
            land.push_back({landStartTime[i], landDuration[i]});

        sort(water.begin(), water.end());
        sort(land.begin(), land.end());

        vector<int> prefWaterDur(m);
        vector<long long> suffWaterFinish(m);

        prefWaterDur[0] = water[0].second;
        for (int i = 1; i < m; i++)
            prefWaterDur[i] =
                min(prefWaterDur[i - 1], water[i].second);

        suffWaterFinish[m - 1] =
            1LL * water[m - 1].first + water[m - 1].second;

        for (int i = m - 2; i >= 0; i--)
            suffWaterFinish[i] =
                min(suffWaterFinish[i + 1],
                    1LL * water[i].first + water[i].second);

        vector<int> prefLandDur(n);
        vector<long long> suffLandFinish(n);

        prefLandDur[0] = land[0].second;
        for (int i = 1; i < n; i++)
            prefLandDur[i] =
                min(prefLandDur[i - 1], land[i].second);

        suffLandFinish[n - 1] =
            1LL * land[n - 1].first + land[n - 1].second;

        for (int i = n - 2; i >= 0; i--)
            suffLandFinish[i] =
                min(suffLandFinish[i + 1],
                    1LL * land[i].first + land[i].second);

        long long ans = LLONG_MAX;

        // Land -> Water
        for (int i = 0; i < n; i++) {
            long long finishLand =
                1LL * landStartTime[i] + landDuration[i];

            ans = min(ans,
                      query(finishLand,
                            water,
                            prefWaterDur,
                            suffWaterFinish));
        }

        // Water -> Land
        for (int i = 0; i < m; i++) {
            long long finishWater =
                1LL * waterStartTime[i] + waterDuration[i];

            ans = min(ans,
                      query(finishWater,
                            land,
                            prefLandDur,
                            suffLandFinish));
        }

        return (int)ans;
    }
};