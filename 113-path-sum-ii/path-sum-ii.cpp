class Solution {
public:
    vector<vector<int>> path;
    vector<int> curr;

    void solve(TreeNode* root, int target) {
        if(root == nullptr) return;

        
        curr.push_back(root->val);

      
        if(root->left == nullptr && root->right == nullptr && target == root->val) {
            path.push_back(curr);
        }

        
        solve(root->left, target - root->val);
        solve(root->right, target - root->val);
        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum);
        return path;
    }
};