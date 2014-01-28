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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        //retrun if it is a leaf node;
        if(root==NULL){
            return result;
        }
        
        vector<int> result1 = postorderTraversal(root->left);
        result.insert(result.end(),result1.begin(),result1.end());
        
        vector<int> result2 = postorderTraversal(root->right);
        result.insert(result.end(),result2.begin(),result2.end());
        
        
        result.push_back(root->val);
        return result;
        
       
    }
};