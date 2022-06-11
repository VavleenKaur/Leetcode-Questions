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
    ListNode* reverse(ListNode* head)
    {
        ListNode* newhead=NULL;
        while(head!=NULL)
        {
            ListNode* next=head->next;
            head->next=newhead;
            newhead=head;
            head=next;
        }
        return newhead;
    }
    void insertAttail(ListNode* &anshead,ListNode* &anstail,int data)
    {   ListNode* temp=new ListNode(data);
        if(anshead==NULL)
        {
           anshead=temp;
            anstail=temp;
            return;
        }
       else
       {
           anstail->next=temp;
           anstail=temp;
           return;
       }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1=reverse(l1);
        ListNode* rl2=reverse(l2);
        
        ListNode* anshead=NULL;
        ListNode* anstail=NULL;
        int carry=0;
        while(rl1!=NULL || rl2!=NULL || carry>0)
        {   int val1=0,val2=0;
            if(rl1!=NULL)
            {
                val1=rl1->val;
            }
            if(rl2!=NULL)
            {
                val2=rl2->val;
            }
            int Val=carry+val1+val2;
            int sum=Val%10;
            carry=Val/10;
            insertAttail(anshead,anstail,sum);
            if(rl1!=NULL)
            {
                rl1=rl1->next;
            }
            if(rl2!=NULL)
            {
                rl2=rl2->next;
            }
        }
        return reverse(anshead);
    }
};