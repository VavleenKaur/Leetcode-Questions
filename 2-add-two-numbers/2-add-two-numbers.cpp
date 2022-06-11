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
    void insertAttail(ListNode* &anshead,ListNode* &anstail,int Val)
    {
        if(anshead==NULL)
        {
        ListNode *temp=new ListNode(Val);
            anshead=temp;
            anstail=temp;
            return;
        }
        else
        {   ListNode *temp=new ListNode(Val);
            anstail->next=temp;
            anstail=temp;
            return;
        }
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *anshead=NULL;
        ListNode *anstail=NULL;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {  int val1=0,val2=0;
            if(l1!=NULL)
        {
            val1=l1->val;
        }
         if(l2!=NULL)
        {
            val2=l2->val;
        }
            int Val=carry+val1+val2;
            int sum=Val%10;
            carry=Val/10;
            insertAttail(anshead,anstail,sum);
            if(l1!=NULL)
            {l1=l1->next;}
            if(l2!=NULL){l2=l2->next;}
        }
      /*  while(l1!=NULL)
        {
            int Val=carry+l1->val;
            int sum=Val%10;
            carry=Val/10;
            insertAttail(anshead,anstail,sum);
            l1=l1->next;
            //l2=l2->next;
        }
         while(l2!=NULL)
        {
            int Val=carry+l2->val;
            int sum=Val%10;
            carry=Val/10;
            insertAttail(anshead,anstail,sum);
            //l1=l1->next;
            l2=l2->next;
        }
        while(carry>0)
        {
            int Val=carry;
            int sum=Val%10;
            carry=Val/10;
            insertAttail(anshead,anstail,sum);
            //l1=l1->next;
            //l2=l2->next;
        }*/
        return anshead;
    }
};