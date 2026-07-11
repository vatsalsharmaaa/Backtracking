class Solution {
public:

    int canmake(int mid,vector<int>&bloomDay,int k){
        int bouquetCount=0;
        int consDays=0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                consDays++;
            }
            else{
                consDays=0;
            }
            if(consDays>=k){
                bouquetCount++;
                consDays=0;
            }

        }
        return bouquetCount;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        int start_day=0;
        int end_day= *max_element(bloomDay.begin(),bloomDay.end());

        int minimum_days=-1;
        while(start_day<=end_day){
            int mid= start_day +(end_day-start_day)/2;

            if(canmake(mid,bloomDay,k)>=m){
                minimum_days= mid;
                end_day=mid-1;

            }
            else start_day=mid+1;
        }

        return minimum_days;

    }
};