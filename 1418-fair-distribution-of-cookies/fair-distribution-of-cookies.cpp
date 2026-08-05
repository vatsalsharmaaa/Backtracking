class Solution {
public:
    

    void solve(int idx,int& res,vector<int>& cookies, int k,int n,vector<int>&child){
        if(idx>=n){
            int maxi_cookie= *max_element(begin(child),end(child));
            res= min(res,maxi_cookie);
            return;
        }

        int cookie= cookies[idx];
        for(int i=0;i<k;i++){
            child[i]+=cookie;
            solve(idx+1,res,cookies,k,n,child);
            child[i]-=cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n= cookies.size();
        int res=INT_MAX;
        vector<int>child(k);

        solve(0,res,cookies,k,n,child);
        return res;

    }
};