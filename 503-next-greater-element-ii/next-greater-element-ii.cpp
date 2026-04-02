// o(n*n) tc will give tle
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>res(n,-1);
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<2*n ;j++){
//                 int id=j%n;
//                 if(nums[id]>nums[i]){
//                     res[i]=nums[id]; break;
//                 }
//             }
//         }
//         return res;
//     }
// };

//optimal stack
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            int curr= nums[i%n];
            while(!st.empty()&&st.top()<=curr){
                st.pop();
            }
            if(i<n){
                nge[i]=st.empty()?-1:st.top();
            }
            st.push(curr);
        }
        return nge;
    }
};