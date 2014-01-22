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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *cur = head;
        int length = 0;
        while(cur){
            cur = cur->next;
            length++;
        }
        cur = head;
        int steps = length -n +1;
        
        if(steps == 1){
            head = head->next;
            return head;
        }
        while(cur&&(steps-2>0)){
            cur = cur->next;
            steps--;
        }
        
        if(cur->next){
            cur->next = cur->next->next;
        }
        return head;
    }
};