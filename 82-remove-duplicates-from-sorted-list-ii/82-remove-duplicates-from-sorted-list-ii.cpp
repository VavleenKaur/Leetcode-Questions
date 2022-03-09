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
        ListNode* temp=head;
        map<int,int>m;
        while(temp!=NULL)
        {
            m[temp->val]++;
            temp=temp->next;
        }
       ListNode* prev=new ListNode(0);
        ListNode *temp1=prev;
        for(auto it:m)
        {
            if(it.second==1)
            {
                ListNode*cur=new ListNode(it.first);
                prev->next=cur;
                prev=cur;
            }
            
        }
        return temp1->next;
    }
};