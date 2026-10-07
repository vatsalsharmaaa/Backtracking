class Solution {
public:
    vector<int>solve_nse(vector<int>& heights,int n){
        vector<int>res(n);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) res[i]=n;
            else res[i]=st.top();
            st.push(i);

        }
        return res;

    }
     vector<int>solve_pse(vector<int>& heights,int n){
        vector<int>res(n);
        res[0]=-1;
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) res[i]=-1;
            else res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int>nse(n);
        vector<int>pse(n);
        nse=solve_nse(heights,n);
        pse=solve_pse(heights,n);

        int res=INT_MIN;
        for(int i=0;i<n;i++){
             int area=0;
            int l=heights[i];
            int b= nse[i] - pse[i] - 1;
            area= l*b;
            res=max(res,area); 
        }
        return res;
    }
};