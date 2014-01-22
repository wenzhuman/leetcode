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
    void reorderList(ListNode *head) {
       ListNode *listCur = head;
       if(head){
        int listLength =1;
        while(listCur){
           listCur = listCur->next;
           listLength++;
        }
       int midWaySteps = listLength/2;
       ListNode *midCur = head;
       midWaySteps--;
       while(midCur&&midWaySteps){
           midCur = midCur->next;
           midWaySteps--;
       }
       ListNode *midNext = midCur->next;
       midCur->next = NULL;
       midNext = reverseList(midNext);
       insertIntoList(head,midNext);
    }
    
    }
    void insertIntoList(ListNode *destHead, ListNode *srcHead){
        ListNode *destCur = destHead;
        ListNode *srcCur = srcHead;
        while(destCur&&srcCur){
            ListNode *destNext = destCur->next;
            ListNode *srcNext = srcCur->next;
            destCur->next = srcCur;
            srcCur->next = destNext;
            destCur = destNext;
            srcCur = srcNext;
        }
    }
    ListNode * reverseList(ListNode *head){
        ListNode *current = head;

            ListNode *nextCur = NULL;
                while(current){
                    ListNode *tmp = current ->next;
                    current->next = nextCur;
                    nextCur = current;
                    current =  tmp;
                }
           return nextCur;
    
        
    }
};