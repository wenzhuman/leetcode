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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rightDepth = 0,leftDepth = 0;
        if(root==NULL) return 0;
        rightDepth = maxDepth(root->right);
        leftDepth = maxDepth(root->left);
        if(rightDepth>=leftDepth)
        {
            return rightDepth+1;
            
        }
        else
        {
            return leftDepth+1;
        }
    }
};