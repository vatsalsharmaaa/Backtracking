class Solution {
public:
    int n,m;
    vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
    int wl;

    bool solve(int idx,int i,int j,string &word,vector<vector<char>>& board)
    {
        if(idx==wl){
            return true;
        }
        
        if(i<0||i>=n||j<0||j>=m||board[i][j]=='$'){
            return false;
        }
        if(board[i][j]!=word[idx]) return false;
        char temp=board[i][j];
        board[i][j]='$';

        for(auto dir:dirs){
            int ni=i+dir[0];
            int nj=j+dir[1];
            if(solve(idx+1,ni,nj,word,board)){
                return true;
            }
        }
        board[i][j]=temp;

        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        wl=word.size();
        m=board[0].size();
          vector<int> freq(128, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                freq[board[i][j]]++;
            }
        }
         if(freq[word[0]] > freq[word[wl - 1]]) {
            reverse(word.begin(), word.end());
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(solve(0,i,j,word,board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
