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
       vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<=n-1;i++)
        {
            if(temp.back()<nums[i])
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
                
            }
        }
    
    return temp.size();
    }
};