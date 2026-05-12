class Solution {
public:
    bool process(vector<vector<int>>& tasks,int mid){
      for(auto &task: tasks){
        int actual= task[0];
        int req= task[1];
        if(mid<req){
            return false;
        }
        mid=mid-actual;
      }

      return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int l=0;
        int r=1e9;

        auto lambda = [](auto& task1,auto& task2){
            int diff1= task1[1]-task1[0];
             int diff2= task2[1]-task2[0];

             return diff1>diff2;

        };
        sort(begin(tasks),end(tasks),lambda);

        int result= INT_MIN;

        while(l<=r){
            int mid= l+(r-l)/2;

            if(process(tasks,mid)){
                result= mid;
                r= mid-1;
               
            }
            else{
               l= mid+1;
            }
        }
        return result;
    }
};