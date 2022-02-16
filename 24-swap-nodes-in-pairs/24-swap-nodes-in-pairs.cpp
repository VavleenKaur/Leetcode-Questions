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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next))
        {
            return head;
        }
       struct ListNode* temp=head; //1
        head=head->next; // 2 3 4
        temp->next=head->next; //2,1->3->4
        head->next=temp; //2->1->3->4
        
        head->next->next=swapPairs(head->next->next);
        return head;
    }
};