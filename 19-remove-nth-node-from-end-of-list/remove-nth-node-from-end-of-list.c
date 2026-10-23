/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head->next==NULL){
        head=NULL;
        return head;
    }
    struct ListNode *itr=head,*prev=NULL;
    int size=0,c=0;
    while(itr){
        size++;
        itr=itr->next;
    }
    n=size-n;
    itr=head;
    while(itr && c<n){
        c++;
        prev=itr;
        itr=itr->next;
    }
    if(n==0){
        head=head->next;
        return head;
    }
    if(!itr){
        prev->next=NULL;
        return head;
    }
    prev->next=itr->next;
    free(itr);
    return head;
}