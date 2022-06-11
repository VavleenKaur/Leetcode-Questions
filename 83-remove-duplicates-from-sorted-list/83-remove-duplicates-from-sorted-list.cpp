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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* nextt=temp->next;
        while(temp!=NULL && nextt!=NULL)
        {
            if(nextt->next!=NULL && temp->val == nextt->val) 
            {   ListNode* temp1=nextt->next;
                temp->next=temp1;
                ListNode* temp2=nextt;
                delete temp2;
                nextt=temp1;
            }
            else if(nextt->next==NULL && temp->val == nextt->val)
            {
                temp->next=NULL;
                ListNode* temp2=nextt;
                delete temp2;
                return head;
                
            }
            else
            {
                temp=nextt;
               nextt=nextt->next;
            }
        }
        return head;
    }
};