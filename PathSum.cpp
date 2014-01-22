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
    bool hasPathSum(TreeNode *root, int sum) {
        set<int> sumSet;
        int initSum = 0;
        traverseBinaryTree(root, initSum, sumSet);
        if(sumSet.find(sum)!=sumSet.end()){
            return true;
        }
        return false;
    }
    void traverseBinaryTree(TreeNode *node,int currentSum, set<int>& sums){
        if(node){
            int thisSum = currentSum+node->val;
            if(!(node->left)&&!(node->right)){
                sums.insert(thisSum);
            }
            if(node->left){
                traverseBinaryTree(node->left,thisSum, sums);
            }
            if(node->right){
                traverseBinaryTree(node->right,thisSum, sums);
            }
        }
    }
};