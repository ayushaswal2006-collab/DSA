/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* insertAtEnd(struct ListNode*head,int data){
    struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val=data;
    temp->next=NULL;
    if(!head){
        head=temp;
        return head;
    }
    struct ListNode *itr=head;
    while(itr->next)
        itr=itr->next;
    itr->next=temp;
    return head;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    struct ListNode *head=NULL;
    struct ListNode *itr1=list1,*itr2=list2,*itr3=head,*prev1=list1,*prev2=list2;
    while(itr1!=NULL && itr2!=NULL){
        if(itr1->val<itr2->val){
        head=insertAtEnd(head,itr1->val);
        itr1=itr1->next;}
        else if(itr2->val<itr1->val){
        head=insertAtEnd(head,itr2->val);
        itr2=itr2->next;}
        else{
            head=insertAtEnd(head,itr1->val);
            head=insertAtEnd(head,itr2->val);
        itr1=itr1->next;
        itr2=itr2->next;
        }
    }
    while(itr1!=NULL){
        head=insertAtEnd(head,itr1->val);
        itr1=itr1->next;
    }
    while(itr2!=NULL){
        head=insertAtEnd(head,itr2->val);
        itr2=itr2->next;
    }
    return head;
}