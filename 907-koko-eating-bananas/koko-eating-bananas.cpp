class Solution {
public:
    bool caneat(vector<int>& piles, int h,int mid){
        int jitnatimelaga=0;

        for(auto x:piles){

            jitnatimelaga+= x/mid;

            if(x%mid!=0){
                jitnatimelaga+=1;
            }
        }
        return jitnatimelaga<=h;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        sort(piles.begin(),piles.end());
        int n= piles.size();
        int left=1;
        int right= piles[n-1];
       

        while(left<right){
            int mid=left+(right-left)/2;

            if(caneat(piles,h,mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};