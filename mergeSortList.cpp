#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *MergeTwoList(ListNode *list1, ListNode *list2){
        cout<<"merge"<<endl;
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
        cout<<"merge end"<<endl;
        return head;
}


ListNode * findMid(ListNode *head){
        cout<<"findMid"<<endl;
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
            cout<<"mid"<<mid->val;

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

void printList(ListNode *head){
    ListNode *cur = head;
    while(cur){
        cout<<"elem"<<cur->val;
        cur = cur->next;
    }
    cout<<endl;
}

int main(){
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);
    //head->next->next->next->next->next = new ListNode(6);
    printList(sortList(head));
}   
   