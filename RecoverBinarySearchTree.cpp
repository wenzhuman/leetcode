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
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        inOrderTraverse(root,prev,first,second);
        if(first&&second){
            swap(first->val, second->val);
            return;
        }
    }
    void inOrderTraverse(TreeNode *root,TreeNode *&prev,TreeNode *&first,TreeNode *&second){
        if(root==NULL) return;
        inOrderTraverse(root->left,prev,first,second);
        if(prev!=NULL){
            if(prev->val>root->val){
                second = root;
                if(!first){
                    first = prev;
                }
            } 
        }
        prev = root;
        inOrderTraverse(root->right,prev,first,second);
    }
};