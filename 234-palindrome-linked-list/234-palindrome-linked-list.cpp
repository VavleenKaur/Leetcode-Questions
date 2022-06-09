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
    ListNode* getMiddle(ListNode* temp)
    {
        ListNode* fast=temp->next;
        ListNode* slow=temp;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode * rev)
    {
        ListNode* newhead=NULL;
        while(rev!=NULL)
        {
            ListNode* next=rev->next;
            rev->next=newhead;
            newhead=rev;
            rev=next;
        }
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        ListNode* temp=head;
        ListNode* middle=getMiddle(temp);
        ListNode* rev=middle->next;
        middle->next=reverse(rev);
        ListNode *head1=head;
        ListNode *head2=middle->next;
        while(head2!=NULL)
        {
            if(head1->val != head2->val)
            {
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
       
        return true;
    }
};