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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        deque<TreeNode*> q1,q2;
        deque<vector<int>> que_result;
        vector<vector<int>> result;
        
        if(root!=NULL){
            q1.push_back(root);
            vector<int> inLoopVector;
            while(true){
                while(!q1.empty()){
                    TreeNode* tmp = q1.front();
                    q1.pop_front();
                    inLoopVector.push_back(tmp->val);
                    TreeNode* tmp_left = tmp->left;
                    TreeNode* tmp_right = tmp->right;
                    if(tmp_left){
                        q2.push_back(tmp_left);
                    }
                    if(tmp_right){
                        q2.push_back(tmp_right);
                    }
                }
                que_result.push_front(inLoopVector);
                
                if(q2.empty()){
                     for(auto ele:que_result){
                        result.push_back(ele);
                    }
                return result;
                }
                q1.insert(q1.end(),q2.begin(),q2.end());
                q2.clear();
                inLoopVector.clear();
            }
        }
        
       
             
        return result; 
    }
};