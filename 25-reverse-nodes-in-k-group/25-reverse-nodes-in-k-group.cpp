/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length( ListNode* head)
    {
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            n++;
        }
        return n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* nh=head;
        if(head==NULL || head->next==NULL || length(head)<k) return head;
        ListNode* newhead=NULL;
         ListNode* nextT=NULL;
        while(nh!=NULL && count<k)
        {
            nextT=nh->next;
            nh->next=newhead;
            newhead=nh;
            nh=nextT;
            count++;
        }
        if(nextT!=NULL)
        {head->next=reverseKGroup(nextT,k);}
        return newhead;
        
    }
};