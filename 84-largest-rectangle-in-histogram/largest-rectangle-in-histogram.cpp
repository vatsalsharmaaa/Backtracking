class Solution {
public:

    vector<int> solveps(vector<int>& heights){
        stack<int>st;
        st.push(-1);
        vector<int>ans(heights.size());

        for(int i=0;i<heights.size();i++){
            while(st.top()!=-1 &&heights[st.top()]>=heights[i]){
                st.pop();
            }  
            ans[i]=st.top();
            st.push(i);  
       }
       return ans;

    }
     vector<int> solvens(vector<int>& heights){
         stack<int>st;
        st.push(-1);
        vector<int>ans(heights.size());
        int n=heights.size();

        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }  
            if(st.top()==-1){
                ans[i]=n;
            }
            else
               ans[i]=st.top();

            st.push(i);  
       }
       return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int>ps(n);
        vector<int>ns(n);
        ps=solveps(heights);
        ns=solvens(heights);
        
        int maxarea=INT_MIN;

        for(int i=0;i<n;i++){
            int l=heights[i];
            int b= ns[i]-ps[i]-1;
            int area= l*b;
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};