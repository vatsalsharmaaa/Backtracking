// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {

//         int n =nums.size();
//         vector<int> count(n+1,0);    THIS APPROACH USES AN EXTRA SPACE 

//         for(int i=0;i<n;i++){
//             count[nums[i]]++;

//         }
//         vector<int>ans;
//         for(int i=0;i<n+1;i++){
//             if(count[i]>1) ans.push_back(i);
//         }
//         if(ans.size()==0 )
//         return{};
//         else
//         return ans;

    
        
//     }
// };
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n= nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]>=0){
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            }
            else
            ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};




















