class Solution { 
public: 
    typedef pair<int,int> p; 
     
    int dist(int a, int b) { 
        return a*a + b*b; 
    } 

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) { 
        vector<vector<int>> ans; 
        priority_queue<p> pq;   // {distance, index}
        int n = points.size(); 
 
        for(int i = 0; i < k; i++){ 
            pq.push({dist(points[i][0], points[i][1]), i}); // CHANGE
        } 

        for(int i = k; i < n; i++){ 

            if(pq.top().first > dist(points[i][0], points[i][1])){ 
                pq.pop(); 
                pq.push({dist(points[i][0], points[i][1]), i}); // CHANGE
            }
        } 
 
        for(int i = 0; i < k; i++){ 
            int idx = pq.top().second;          // CHANGE
            ans.push_back(points[idx]);         // CHANGE
            pq.pop(); 
        } 

        return ans; 
    } 
};