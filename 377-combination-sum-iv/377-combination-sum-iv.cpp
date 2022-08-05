class Solution {
public:
    int memo(vector<int>&dp,vector<int>&nums,int tar)
    {
        if(tar==0) return 1;
        if(tar<0) return 0;
        
        if(dp[tar]!=-1) return dp[tar];
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {  sum+=memo(dp,nums,tar-nums[i]);
        }
        return dp[tar]=sum;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
       vector<int>dp(target+1,-1);
        return memo(dp,nums,target);
    }
};