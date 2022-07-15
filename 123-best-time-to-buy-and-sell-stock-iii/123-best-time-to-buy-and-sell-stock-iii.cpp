class Solution {
public:
//     int memo(int ind,int canBuy,int k,vector<vector<vector<int>>>& dp,vector<int>&prices,int n)
//     {   if(k==0) return 0;
//         if(ind==n) return 0;
//         if(dp[ind][canBuy][k]!=-1) return dp[ind][canBuy][k];
//         if(canBuy)
//         {
//            return dp[ind][canBuy][k]=max(-prices[ind]+memo(ind+1,0,k,dp,prices,n),0+memo(ind+1,1,k,dp,prices,n));
//         }
//         else
//         {
//            return dp[ind][canBuy][k]=max(prices[ind]+memo(ind+1,1,k-1,dp,prices,n),0+memo(ind+1,0,k,dp,prices,n));
//         }
//     }
    int maxProfit(vector<int>& prices) {
       int k=2;
       int n=prices.size();
       vector<vector<int>>ahead(2,vector<int>(k+1,0));
       vector<vector<int>>curr(2,vector<int>(k+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            
                for(int trans=1;trans<=k;trans++)
                {
           curr[1][trans]=max(-prices[ind]+ahead[0][trans],0+ahead[1][trans]);
       
            curr[0][trans]=max(prices[ind]+ahead[1][trans-1],0+ahead[0][trans]);
    
                }
            ahead=curr;
            
        }
        return ahead[1][k];
    }
};
