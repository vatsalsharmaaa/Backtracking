class Solution {
public:
    bool hasPathSum(TreeNode* root, int x) {
       
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL)return x==root->val;
        

        return (hasPathSum(root->left,x-root->val)|| hasPathSum(root->right,x-root->val));
    }
};