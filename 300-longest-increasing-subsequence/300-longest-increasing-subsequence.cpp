class Solution {
public:
    int f(int ind,int prev_ind,vector<int>&nums,vector<vector<int>>&dp)
    {   if(ind==nums.size()) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int len=f(ind+1,prev_ind,nums,dp);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
        {
            len=max(len,1+f(ind+1,ind,nums,dp));
        }
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       vector<int>ahead(n+1,0),cur(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                int len=ahead[j+1];
        if(j==-1 || nums[i]>nums[j])
        {
            len=max(len,1+ahead[i+1]);
        }
               cur[j+1]=len;
            }
             ahead=cur;   
        }
        return ahead[0];
    }
};