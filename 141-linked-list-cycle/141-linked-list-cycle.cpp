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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        {
            return false;
        }
        unordered_map<ListNode*,bool> mp_visited;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(mp_visited[temp]==true)
            {
                return true;
            }
            mp_visited[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};