/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
         ListNode *outCur = head;
         ListNode *next;
        while(outCur&&outCur->next){
            next = outCur->next;
            ListNode*ptr = outCur->next;
            int value = ptr->val;
            bool flag = false;
            ListNode* inCur = head;
            
            while(inCur&&inCur!=ptr){
                if(value < inCur->val){
                    if(inCur->next!=ptr){
                        //delete node
                        outCur->next = ptr->next;
                        flag = true;
                        //insert node
                        ListNode*tmp = inCur->next;
                        inCur->next = ptr;
                        ptr->next = tmp;
                    }
                    //swap two values
                    int tmpValue = inCur->next->val;
                    inCur->next->val = inCur->val;
                    inCur->val = tmpValue ;
                    
                    break;
                }
                inCur = inCur->next;
            }
            
            if(!flag){
                outCur = outCur->next;
            }
        }
        return head;
    }

};