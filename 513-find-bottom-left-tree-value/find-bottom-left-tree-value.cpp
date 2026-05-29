int maxdepth;
int answer;
class Solution {
public:

    void dfs(TreeNode* root, int currDepth){
        if(!root) return ;
        if(currDepth> maxdepth){
            maxdepth= currDepth;
            answer= root->val;
        }
        dfs(root->left,currDepth+1);
        dfs(root->right,currDepth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        maxdepth= -1;
        dfs(root,0);

        return answer;
    }
};