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
    ListNode *cycledetect(ListNode *head)
    {   if(head==NULL) return NULL;
        ListNode *fast=head;
        ListNode *slow=head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return slow;
        }
     
     return NULL;
        
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *cycle=cycledetect(head);
        if(cycle==NULL) return NULL;
        ListNode* slow=head;
        while(slow!=cycle)
        {
            slow=slow->next;
            cycle=cycle->next;
        }
        return slow;
    }
};