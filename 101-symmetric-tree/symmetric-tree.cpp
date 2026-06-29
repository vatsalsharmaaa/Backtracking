/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool solve(TreeNode* n1 , TreeNode* n2){
        
        if(n1==nullptr && n2==nullptr) return true;
        // if(!n1 && n2!=nullptr) return false;
        // if(n1!=nullptr && !n2) return false;

        //agar dono null hote toh uppar se hojata return true
        if(!n1 || !n2) return false;

        if(n1->val != n2->val) return false;
        bool lefty= solve(n1->left, n2->right);
        bool rigthy= solve(n1->right,n2->left);

        return lefty && rigthy;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return solve(root->right , root->left);
    }
};