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
    
    int sumNumbers(TreeNode *root) {
        if(root){
        return calSum(root,0);
        }
        else{
            return 0;
        }
    }
    int calSum(TreeNode *root,int path){
        
        if(!root->left&&!root->right){
            return path*10+root->val;
        }
        int sum = 0;
        if(root->left){
            sum += calSum(root->left,path*10+root->val);
        }
        if(root->right){
            sum += calSum(root->right,path*10+root->val);
        }
        return sum;
    }
};