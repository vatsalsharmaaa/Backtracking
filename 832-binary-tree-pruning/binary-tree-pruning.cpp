class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr)return NULL;
        
        root->left= pruneTree(root->left);
        root->right=pruneTree(root->right);

        if(root->left==nullptr && root->right==nullptr&&root->val==0){
            return NULL;
        }
        return root;
    }
};