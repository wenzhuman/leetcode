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
    ListNode *MergeTwoList(ListNode *list1, ListNode *list2){
        
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        ListNode *head = list1->val<list2->val?head1:head2;
        ListNode *cur = head;


        if(cur==head1) head1 = head1->next;
        else head2 = head2->next;
        
        while(head1!=NULL|head2!=NULL){
            //find the smaller node
            ListNode*smaller = NULL;
            if(!head1){
                smaller = head2;
                head2 = head2->next;
            }
            else if(!head2){
                smaller = head1;
                head1 = head1->next;
            }
            else if(head1->val<head2->val) {
                smaller = head1;
                head1 = head1->next;
            }
            else {
                smaller = head2;
                head2 = head2->next;
            }
            //insert the smaller node
            if(smaller!=cur->next){
                ListNode* tmpNext = cur->next;
                cur->next = smaller;
                smaller->next = tmpNext;
            }
            cur = cur->next;
        }
        
        return head;
}


ListNode * findMid(ListNode *head){
        
        int n = 1;
        ListNode *cur=head, *mid = head;
        while(cur){
            n++;
            cur = cur->next;
        }
        int steps = n/2-1;
        while(steps){
            mid = mid->next;
            steps--;
        }
        return mid;
}

 ListNode *mergeSort(ListNode *head){
        //one element,no need to sort,return
        if(head&&head->next==NULL) return head;
        else {
            ListNode * mid = findMid(head);
            ListNode* midNext = mid->next;
            mid->next = NULL;
            ListNode * node1 = mergeSort(head);
            ListNode * node2 = mergeSort(midNext);
            return MergeTwoList(node1,node2);
        }
}

ListNode *sortList(ListNode *head) {
        if(head){
            return mergeSort(head);
        }
        return head;
}
};