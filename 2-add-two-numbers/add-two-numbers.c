/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *itr1=l1,*itr2=l2,*prev1,*prev2;
    int temp=0;
   while(itr1 && itr2){
    itr2->val=itr1->val+itr2->val+temp;
    if(itr2->val>9){
    temp=itr2->val/10;
    itr2->val=itr2->val%10;}
    else 
    temp=0;
    prev1=itr1;
    prev2=itr2;
    itr1=itr1->next;
    itr2=itr2->next;
   }
   while(itr1!=NULL){
    itr1->val+=temp;
    if(itr1->val>9){
        temp=itr1->val/10;
        itr1->val=itr1->val%10;
    }
    else 
    temp=0;
    prev2->next=itr1;
    prev2=itr1;
    itr1=itr1->next;
   }
   while(itr2!=NULL){
    itr2->val=itr2->val+temp;
    if(itr2->val>9){
        temp=itr2->val/10;
        itr2->val=itr2->val%10;
    }
    else
    temp=0;
    prev2=itr2;
    itr2=itr2->next;
   }
   if(temp!=0){
    struct ListNode *cur=(struct ListNode*)malloc(sizeof(struct ListNode));
    cur->val=temp;
    cur->next=NULL;
    prev2->next=cur;
   }
   return l2;
}