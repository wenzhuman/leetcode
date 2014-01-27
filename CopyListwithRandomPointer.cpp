/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return head;
        RandomListNode *cur = head;
        RandomListNode *copyResult = NULL;
        //copy the node to the next
        while(cur){
            RandomListNode* copy = new RandomListNode(cur->label);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        cur = head;
        RandomListNode *copyCur = cur->next;
        copyResult = copyCur;
        
        while(copyCur){
            copyCur->random = cur->random == NULL ? NULL : cur->random->next;
            if(copyCur->next){
                copyCur = copyCur->next->next;
                cur = cur->next->next;
            }
            else{
                break;
            }
        }
        cur = head;
        while(cur->next){
            RandomListNode* tmpNext = cur->next;
            cur->next = cur->next->next;
            cur = tmpNext;
        }
        return copyResult;
    }
};