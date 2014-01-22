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
    bool isBalanced(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL) return true;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        bool isBalancedLeft = isBalanced(root->left);
        bool isBalancedRight = isBalanced(root->right);
        if(abs(left-right)>1||!isBalancedLeft||!isBalancedRight)
            return false;
        return true;
    }
    int getHeight(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return max(leftHeight,rightHeight)+1;
    }
};