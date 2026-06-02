class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long landMin = LLONG_MAX;
        for (int i = 0; i < landStartTime.size(); i++)
            landMin = min(landMin,
                          (long long)landStartTime[i] + landDuration[i]);

        long long waterMin = LLONG_MAX;
        for (int i = 0; i < waterStartTime.size(); i++)
            waterMin = min(waterMin,
                           (long long)waterStartTime[i] + waterDuration[i]);

        long long ans = LLONG_MAX;

        // Land -> Water
        for (int i = 0; i < waterStartTime.size(); i++)
            ans = min(ans,
                      max(landMin, (long long)waterStartTime[i]) +
                      waterDuration[i]);

        // Water -> Land
        for (int i = 0; i < landStartTime.size(); i++)
            ans = min(ans,
                      max(waterMin, (long long)landStartTime[i]) +
                      landDuration[i]);

        return ans;
    }
};