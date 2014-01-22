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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!q&&!p) return true;
        else if((!q&&p)|(q&&!p)) return false;
        else if(q->val!=p->val) return false;
        else return isSameTree(p->left,q->left)&isSameTree(p->right,q->right);
    }
};