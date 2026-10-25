/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head || !head->next)
    return false;
    struct ListNode *slow=head,*fast=head,*itr=head;
    while(itr && itr->next && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
        itr=itr->next;
    }
    if(slow==fast)
    return true;
    else
    return false;
}