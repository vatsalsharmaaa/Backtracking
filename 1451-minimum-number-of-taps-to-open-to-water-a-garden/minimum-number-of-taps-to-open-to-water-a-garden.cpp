class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
       
        vector<int>data(n+1);

        for(int i=0;i<=n;i++){
            int left  = max(0, i-ranges[i]);   //to save out of bound conditionssss max min
            int right = min(n,i+ranges[i]);

            data[left]= max(data[left],right);
        }
        int taps=0;
        int currend=0;
        int maxend=0;

        for(int i=0;i<=n;i++){

            if(i>maxend){
                return -1;
            }
            if(i>currend){
                taps++;
                currend=maxend;
            }

            maxend= max(maxend,data[i]);
        }

        return taps;
    }
};