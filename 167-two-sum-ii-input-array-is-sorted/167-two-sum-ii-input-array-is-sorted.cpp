class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left=0;
        vector<int>res;
        int right=nums.size()-1;
        while(left<=right)
        {
            if(nums[left]+nums[right]==target) 
            {
                res={left+1,right+1};
                return res;
            }
            else if(nums[left]+nums[right]<target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};