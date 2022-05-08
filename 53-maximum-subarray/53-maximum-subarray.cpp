class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
     int n=nums.size();
        if(n==1) return nums[0];
        int sum=nums[0],maxi=nums[0];
        for(int i=1;i<n;i++)
        {
            if(sum+nums[i]>nums[i]) sum=sum+nums[i];
            else
                {
                    sum=nums[i];
                }
            if(sum>maxi)
            {
                maxi=sum;
            }
        }
        return maxi;
    }
};