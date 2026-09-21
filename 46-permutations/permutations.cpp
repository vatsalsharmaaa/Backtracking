class Solution {
public:
    vector<vector<int>> ans;
    set<int> st; 

    void solve(vector<int>& nums, vector<int>& temp) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) == st.end()) {

                st.insert(nums[i]); //do
            temp.push_back(nums[i]);
     
                solve(nums, temp);//explore

                st.erase(nums[i]);//hata deeeeeee
              temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(nums, temp);
        return ans;
    }
};
