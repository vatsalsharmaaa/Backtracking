class Solution {
public:

    string getsubTree(vector<TreeNode*>&res, unordered_map<string,int>&mp,TreeNode* root){
        if(root==NULL) return "N";
        string s= to_string(root->val)+","
        +getsubTree(res,mp,root->left)+","
        +getsubTree(res,mp,root->right);

        if(mp[s]==1){
            res.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
        vector<TreeNode*>res;
        getsubTree(res,mp,root);
        return res;
    }
};