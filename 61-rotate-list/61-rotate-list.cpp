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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
        {
            return head;
        }
        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        //cout<<len;
        k%=len;
        while(k--)
        {
            ListNode* prev=NULL;
            ListNode*cur=head;
            while(cur->next)
            {
                prev=cur;
                cur=cur->next;
            }
            prev->next=NULL;
            cur->next=head;
            head=cur;
        }
        return head;
    }
};