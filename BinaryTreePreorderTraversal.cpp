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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       vector<int> result;
        if(root == NULL) return result;
        result.push_back(root->val);
        
        
       
            vector<int> result1 = preorderTraversal(root->left);
            result.insert( result.end(), result1.begin(), result1.end() );
        
       
       
            vector<int> result2 = preorderTraversal(root->right);
            result.insert( result.end(), result2.begin(), result2.end() );
 
        
       
 
    }
};