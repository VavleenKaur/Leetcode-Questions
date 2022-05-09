class Solution {
public:
   /* int f(int ind,int prev_ind,vector<int>&nums,vector<vector<int>>&dp)
    {   if(ind==nums.size()) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int len=f(ind+1,prev_ind,nums,dp);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
        {
            len=max(len,1+f(ind+1,ind,nums,dp));
        }
        return dp[ind][prev_ind+1]=len;
    }*/
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
    }
    return *max_element(dp.begin(),dp.end());
    }
};