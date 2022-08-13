class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //linkedlist cycle approach
        int slow=nums[0];
        int fast=nums[0];
        do
        {
            slow=nums[slow];
            cout<<slow;
            fast=nums[nums[fast]];
            cout<<fast;
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};