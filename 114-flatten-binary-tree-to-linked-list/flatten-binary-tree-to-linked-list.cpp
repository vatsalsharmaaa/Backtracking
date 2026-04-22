// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         TreeNode* curr= root;
//         while(curr!=NULL){

//             if(curr->left==NULL){
//                 curr=curr->right;
//             }
//             else {
//                 TreeNode * leftchild=curr->left;
//                 while(leftchild->right!=NULL){
//                     leftchild=leftchild->right;
//                 }
//                 leftchild->right=curr->right;
//                

//                 //del connection
//                 TreeNode * temp=curr;
//                 curr=curr->left;
//                 temp->right=NULL;
//             }
//         }
//     }
// };
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != NULL) {

            if (curr->left == NULL) {
                curr = curr->right;
            } else {
                TreeNode* leftchild = curr->left;

                // find rightmost node of left subtree
                while (leftchild->right != NULL) {
                    leftchild = leftchild->right;
                }

                // connect right subtree
                leftchild->right = curr->right;

                // move left subtree to right
                curr->right = curr->left;

                // remove left link
                curr->left = NULL;

                // move forward
                curr = curr->right;
            }
        }
    }
};