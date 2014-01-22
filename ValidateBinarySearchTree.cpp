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
    bool isValidBST(TreeNode *root) {
        
        if(!root) return true;
        return checckBST(root,-1*INT_MAX,INT_MAX);
        
    }
    bool checckBST(TreeNode *root,int thresHold1,int thresHold2){
        if(!root) return true;
        if(root->val >= thresHold2) return false;
        if(root->val <= thresHold1) return false;
        if(root->left){
            if(root->left->val>=root->val) return false;
        }
        
        bool left = true,right = true;
        
        if(root->val<thresHold2){
             left = checckBST(root->left,thresHold1,root->val);
        }
        else{
            left = checckBST(root->left,thresHold1,thresHold2);
        }
        
        if(root->right){
            if(root->right->val<=root->val) return false;
        }
        if(root->val > thresHold1){
            right = checckBST(root->right,root->val,thresHold2);
        }
        else{
            right = checckBST(root->right,thresHold1,thresHold2);
        } 
        
        if(!left||!right) return false;
        
        return true;
    }
};