class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
       //vector<int>dp(n,-1);
        //dp[0]=nums[0];
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)pick+=prev2;
            int notpick=0+prev;
           int  curi=max(pick,notpick);
            prev2=prev;
            prev=curi;
        }
         return prev;
    }
};