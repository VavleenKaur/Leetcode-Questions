class Solution {
public:
    int f(int ind,int tar,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(ind==0) 
        {
            if(tar==0 && nums[ind]==0) return 2;
            if(tar==0 || nums[ind]==tar) return 1;
            else return 0;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        else
        {
            int notpick=f(ind-1,tar,nums,dp);
            int pick=0;
            if(nums[ind]<=tar)
            { pick= f(ind-1,tar-nums[ind],nums,dp);
            }
            return dp[ind][tar]=pick+notpick;
        }
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums)
        {
            sum+=i;
        }
        // sum=s1+s2 s1-s2=target sum=target+2s2
        if((sum-target)<0 || (sum-target)%2) return 0;
        int tar=(sum-target)/2;
        vector<int>prev(tar+1,0);
          if(nums[0] == 0)prev[0]=2;
        else prev[0]=1;
        if(nums[0]!=0 && nums[0]<=tar)prev[nums[0]]=1;
        for(int i=1;i<n;i++)
        {   vector<int>cur(tar+1,0);
            for(int j=0;j<=tar;j++)
            {
                int notake=prev[j];
                int take=0;
                if(nums[i]<=j) take=prev[j-nums[i]];
                cur[j]=take+notake;
            }
         prev=cur;
        }
        return prev[tar];
    }
};