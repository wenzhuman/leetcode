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
    ListNode *swapPairs(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode* origin = head;
        while(head&&head->next){
            ListNode*p1 = head;
            ListNode*p2 = head->next;
            int tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
            head = head->next->next;
        }
        return origin;
    }
};