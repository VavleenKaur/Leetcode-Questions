class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
     int n=nums.size();
        if(n==1) return nums[0];
        int sum=-1e9,maxi=-1e9;
        for(int i=0;i<n;i++)
        {
            sum=max(nums[i],sum+nums[i]);
            maxi=max(sum,maxi);
        }
        return maxi;
    }
};