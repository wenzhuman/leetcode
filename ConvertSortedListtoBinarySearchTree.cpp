#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
     ListNode * findMid(ListNode *head){
        if(head == NULL) return NULL;
        int n = 1;
        ListNode *cur=head, *mid = head;
        cout<<"log3"<<endl;
        while(cur){
            cur = cur->next;
            n++;
        }
        cout<<"log4"<<endl;

        int steps = n/2-1-1;
        while(steps>0){
            mid = mid->next;
            steps--;
        }
        return mid;
    }
TreeNode *sortedListToBST(ListNode *head) {
        TreeNode *result = NULL;
        if(head == NULL) return result;
        if(head->next == NULL) return new TreeNode(head->val);
        cout<<"log1"<<endl;
        ListNode *mid = findMid(head);
        cout<<"log2"<<endl;
        if(mid&&mid->next!=NULL){
            ListNode* midNext = mid->next;
            result = new TreeNode(midNext->val);
            ListNode * tmpNext = midNext->next;
            mid->next = NULL;
            result->left = sortedListToBST(head);
            result->right = sortedListToBST(tmpNext);
            
        }
        return result;
    }

    int main(){
      ListNode *a = new ListNode(1);
      a->next = new ListNode(3);
      sortedListToBST(a);

    }
   