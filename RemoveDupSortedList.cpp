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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL) return head;
        ListNode* middle = head;
        ListNode* tail = head;
        while(tail){
            int thisVal = tail->val;
            tail = tail->next;
            while(tail&&thisVal == tail->val){//the sequence of the right hand and the left hand matters!!!!!!
                tail = tail->next;
            }
           
           middle->next = tail;
           if(middle){
                middle = middle->next;
           }
        }
        return head;
    }
};