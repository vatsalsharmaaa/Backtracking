class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;

        TreeNode* curr= root;
        while(curr!=NULL){
             if(curr->left==NULL){
            result.push_back(curr->val);
            curr=curr->right;
              }
              else{
                TreeNode* leftchild= curr->left;
                while(leftchild->right!=NULL){
                   leftchild= leftchild->right;
                }
                leftchild->right= curr;
                TreeNode* temp= curr;
                curr= curr->left;
                temp->left=NULL;
              }
        }
        return result;

       
    }
};