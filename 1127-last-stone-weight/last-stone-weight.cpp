class Solution {
public:
    typedef pair<int ,int>p;
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<p,vector<p>>pq;
        for(int i=0;i<n;i++){
            pq.push({stones[i],i});
        }
        while(pq.size()>1){
            auto p1= pq.top();
            pq.pop();
            auto p2=pq.top();
            pq.pop();

            int y=p1.first;
            int x=p2.first;
            if(x==y){
                continue;
            }
            else if(y>x){
                y-=x;
                pq.push({y,p1.second});
            }
        }
        if(pq.empty()){
            return 0;
        }
        else return pq.top().first;
    }
};