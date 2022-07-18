class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()<=1) return nums;
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n,1);
        int maxi=0,last_index=0;
        for(int i=1;i<n;i++)
        {  
            for(int prev=0;prev<i;prev++)
            {   
                if(nums[i]% nums[prev]==0)
                {
                    if(dp[prev]+1>dp[i])
                    {
                        dp[i]=dp[prev]+1;
                        hash[i]=prev;
                    }
                }
            }
            if(dp[i]>maxi)
            {
               maxi=dp[i];
               last_index=i;
            }
        }
        
        vector<int>res(maxi);
        for(int i=maxi-1;i>=0;i--)
        {
            res[i]=nums[last_index];
            last_index=hash[last_index];
        }
        
        return res;
    }
};