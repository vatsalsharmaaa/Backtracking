// o(n*n)
// class Solution {
// public:
//     int longestNiceSubarray(vector<int>& nums) {
//         int n=nums.size();
//     int result= 0;
//         for(int i=0;i<n;i++){
//             int mask= 0;
//             for(int j=i;j<n;j++){
//                 if((mask & nums[j])!=0){
//                     break;
//                 }
//                 else{
//                     mask|=nums[j];
                    
//                 }
//                 result= max(result,j-i+1);
                
//             }
//         }
//         return result;
//     }
// };

//sliding window o(n)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int result=0;
        
        int mask=0;

        while(j<n){
            while((mask & nums[j])!=0){
                mask=( mask ^ nums[i]);
                i++;
            }
            result= max(result,j-i+1);
            mask|= nums[j];
            
            j++;
        }
        return result;
    }
};



















