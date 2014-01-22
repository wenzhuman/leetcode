/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       if(root == NULL) return true;
       else return isSymmetric(root->left,root->right);
     }
    bool isSymmetric(TreeNode* left,TreeNode* right){
        if(left == NULL) return right == NULL;
        else if(right == NULL) return left == NULL;
        else {
            if(left->val!=right->val) return false;
            
            if(!isSymmetric(left->left,right->right)) return false;
            
            
            if(!isSymmetric(left->right,right->left)) return false;
        }
        return true;
    }
};