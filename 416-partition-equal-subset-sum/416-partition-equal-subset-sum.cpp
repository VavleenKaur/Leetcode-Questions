class Solution {
public:
    bool f(int ind,int k,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(k==0) return true;
        if(ind==0) return arr[ind]==k;
        if(dp[ind][k]!=-1) return false;
        else
        {
            bool notpick=f(ind-1,k,arr,dp);
            bool pick=false;
            if(arr[ind]<=k)
            {
                pick=f(ind-1,k-arr[ind],arr,dp);
            }
            return dp[ind][k]=pick|| notpick;
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
        {
            sum+=i;
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);
        
    }
};