class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++)
        {   
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    if(dp[prev]+1>dp[i])
                    {
                        dp[i]=dp[prev]+1;
                    }
                }
            }
        }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=maxi<dp[i]?dp[i]:maxi;
    }
        return maxi;
    }
};