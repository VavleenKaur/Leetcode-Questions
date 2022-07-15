class Solution {
public:
    // int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp,int n)
    // {   if(ind>=n) return 0;
    //     if(dp[ind][buy]!=-1)return dp[ind][buy];
    //     if(buy)
    //     {
    //         return dp[ind][buy]=max((-prices[ind]+f(ind+1,0,prices,dp,n)),(f(ind+1,1,prices,dp,n)));
    //    }
    //     else
    //      {
    //         return dp[ind][buy]=max(prices[ind]+f(ind+2,1,prices,dp,n),f(ind+1,0,prices,dp,n));      
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int curr_buy=0,curr_sell=0,ahead_buy=0,ahead_sell=0,ahead2_buy=0;
        
        for(int ind=n-1;ind>=0;ind--)
        {
            
           curr_buy=max(-prices[ind]+ahead_sell,0+ahead_buy);
       
            curr_sell=max(prices[ind]+ahead2_buy,0+ahead_sell);
    
            ahead2_buy=ahead_buy;
            ahead_buy=curr_buy;
            ahead_sell=curr_sell;
            
        }
        return ahead_buy;
    }
};