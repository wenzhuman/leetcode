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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(num.size() == 0) return NULL;  //add this to fix bug
        int begin = 0;
        int end = num.size()-1;
        int middle = (begin+end)/2;
        TreeNode* root = new TreeNode(num[middle]);
        vector<int> left(num.begin(),num.begin()+middle);
        root->left = sortedArrayToBST(left);
       
        vector<int> right(num.begin()+middle+1,num.end());
        root->right = sortedArrayToBST(right);
        
        
        return root;
    }
};