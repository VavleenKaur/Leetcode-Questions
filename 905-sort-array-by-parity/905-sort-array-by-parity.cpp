class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int slow=0,fast=0;
        int n=nums.size();
        while(slow<=fast && fast<=n-1)
        {
            if(nums[slow]%2==0)
            {
                slow++;
                
            }
            else if(nums[slow]%2!=0 && nums[fast]%2==0)
            {
                swap(nums[slow],nums[fast]);
                slow++;
            }
            fast++;
        }
        return nums;
    }
};