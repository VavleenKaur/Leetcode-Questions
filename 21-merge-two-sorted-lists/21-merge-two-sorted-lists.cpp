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
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(0);
        ListNode *temp1=list1;
        ListNode *temp2=list2,*merged=ans;
       
      while(temp1 && temp2)
      {
         if(temp1->val<=temp2->val)
         {
             merged->next=temp1;
              temp1=temp1->next;
         }
          else
          {
              merged->next=temp2;
              temp2=temp2->next;
          }
          merged=merged->next;
          
      }
        if(temp1)
          {
              merged->next=temp1;
          }
          else
          {
              merged->next=temp2;
          }
        return ans->next;
       
    }
};