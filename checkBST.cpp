#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
   bool checckBST(TreeNode *root,int thresHold,int greaterOrLess){
        if(!root) return true;
        
        if(root->left){
            if(root->left->val >= root->val) return false;
            if(greaterOrLess == 1){
                cout<<"left"<<root->left->val<<"thresHold" << thresHold<<endl;
                if( root->left->val <= thresHold) {cout<<"false";return false;}
            }
            
            bool left = checckBST(root->left,root->val,0);
            if(!left) return false;
        }
        if(root->right){
            if(root->right->val <= root->val) return false;
            if(greaterOrLess == 0){
                if( root->right->val >= thresHold) return false;
            }
            bool right = checckBST(root->right,root->val,1);
            if(!right) return false;
        }
        
        return true;
}
bool isValidBST(TreeNode *root) {
        
        if(!root) return true;
        if(root->left){
            if(root->left->val >= root->val) return false;
            bool left = checckBST(root->left,root->val,0);
            if(!left) return false;
        }
        if(root->right){
            if(root->right->val <= root->val) return false;
            bool right = checckBST(root->right,root->val,1);
            if(!right) return false;
        }
        return true;
        
    }
   
int main(){
    TreeNode* a = new TreeNode(3);

    TreeNode* b1 = new TreeNode(1);
    TreeNode* b2 = new TreeNode(5);
    a->left = b1;
    a->right = b2;
    TreeNode* c1 = new TreeNode(0);
    TreeNode* c2 = new TreeNode(2);
    b1->left = c1;
    b1->right = c2;
    TreeNode* d1 = new TreeNode(4);
    TreeNode* d2 = new TreeNode(6);
    b2->left = d1;
    b2->right = d2;
    TreeNode* e = new TreeNode(3);
    c2->right = e;
    cout<<isValidBST(a)<<endl;
}