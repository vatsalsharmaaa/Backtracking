/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* LCA(TreeNode* root,TreeNode* p, TreeNode* q){
       if(!root) return NULL;
        if(root->val==p->val || root->val==q->val) return root;

        TreeNode* leftLCA= LCA(root->left,p,q);
        TreeNode* rightLCA= LCA(root->right,p,q);

        if(leftLCA && rightLCA) return root;
        else if(leftLCA) return leftLCA;
        else if(rightLCA) return rightLCA; 

        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        return LCA(root,p,q);
    }
};