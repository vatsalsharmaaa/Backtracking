class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>freq;
        int count=0;

        for(auto x: nums){
            freq[x]++;
        }
        for(auto &it : freq){
            int num= it.second;
            if(num==1){
                return -1;

            }
            else{
                count+= ceil(double(num)/3);
            }
        }
        return count;
    }
};