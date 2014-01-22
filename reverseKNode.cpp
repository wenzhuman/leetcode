#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode *findKthNode(ListNode *head,int k);
ListNode *reverseK(ListNode *head, int k);
int lengthOfList(ListNode *head);
void printList(ListNode *head);

void printList(ListNode *head){
    ListNode *cur = head;
    while(cur){
        cout<<"elem"<<cur->val;
        cur = cur->next;
    }
    cout<<endl;
}
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head) return head;
        if(k == 1) return head;
        int length = lengthOfList(head);
        if(length<k){
            reverseK(head,length);
        }
        
    }
    ListNode *reverseK(ListNode *head, int k){
        ListNode *cur = findKthNode(head,k);
        
        ListNode *tailNext = cur->next;
        
        ListNode *curNext = reverseKGroup(head,k-1);
        
        ListNode *oldTail = findKthNode(curNext,k-1);
        
        oldTail->next = tailNext;
        
        cur->next = curNext;
        
        return cur;
    }
    ListNode *findKthNode(ListNode *head,int k){
        int step = k-1;
        
        ListNode *cur = head;
        
        while(step&&cur->next){
            step--;
            cur = cur->next;
        }
        return cur;
    }
    int lengthOfList(ListNode *head){
        int step = 0;
        ListNode *cur = NULL;
        if(head){
            cur = head;
            step++;
        }
        while(cur->next){
            step++;
            cur = cur->next;
        }
        return step;
    }
    int main(){
    	ListNode* head = new ListNode(1);
    	//head->next = new ListNode(2);
    	printList(reverseKGroup(head,2));

    }