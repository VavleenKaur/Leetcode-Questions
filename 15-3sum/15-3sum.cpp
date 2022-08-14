class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size()-1;i++)
        {
            int target =-nums[i];
            int left=i+1;
            int right=nums.size()-1;
            while(left<right)
            {
                if(nums[left]+nums[right]==target)
                {
                    vector<int>v;
                    v={nums[i],nums[left],nums[right]};
                    int num2=nums[left];
                    int num3=nums[right];
                    res.push_back(v);
                    while(left<right && nums[left]==num2) left++;
                    while(left<right && nums[right]==num3) right--;
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
            while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};