
// class Solution {
// public:
//     int maxdiff;

//     void solvehelper(TreeNode * root,TreeNode * child){
//         if(root==NULL || child==NULL) return ;

//         maxdiff= max(maxdiff, abs(root->val - child->val));
//         solvehelper(root,child->left);
//         solvehelper(root,child->right);

//     }

//     void solve(TreeNode* root){
//         if(root==NULL) return;

//         solvehelper(root,root->left);
//         solvehelper(root,root->right);

//         solve(root->left);
//         solve(root->right);
//     }
//     int maxAncestorDiff(TreeNode* root) {
//         maxdiff=-1;
//         solve(root);
//         return maxdiff;
//     }
// };
class Solution {
public:
    int findmax(TreeNode * root, int minv,int maxv){
        if(!root){
            return abs(minv-maxv);

        }
        minv=min(minv,root->val);
        maxv=max(maxv,root->val);
        int l=findmax(root->left,minv,maxv);

        int r=findmax(root->right,minv,maxv);

        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return findmax(root,root->val,root->val);
    }
};