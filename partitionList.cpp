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
    ListNode *partition(ListNode *head, int x) {
        ListNode *result = head;
        if(head ==NULL||head->next==NULL) return head;
        ListNode * inserPos = NULL;
        ListNode * cur = NULL;
        if(head->val<x){
            inserPos = head;
        }
        while(inserPos && inserPos->next && inserPos->next->val<x){
            inserPos=inserPos->next;
        }
        if(inserPos){
                cur = inserPos;
        }
        else{
            cur = head;
        }
        while(cur&&cur->next){
            
                if(cur->next->val>=x){
                    cur = cur->next;           
                }
                else{
                    ListNode*insertNode = cur->next;
                    ListNode*curNext = insertNode->next;
                    
                    cur->next = cur->next->next;
                    ListNode *tmpNext = head;
                    
                    if(inserPos){
                        tmpNext = inserPos->next;
                        inserPos->next = insertNode;
                        inserPos = inserPos->next;
                    }
                    
                    insertNode->next = tmpNext;
                    
                    if(!inserPos){
                        result = insertNode;
                        inserPos = insertNode;
                    }
                    //cur = curNext;
                }
        }
        return result;
    }
};