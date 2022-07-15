class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int curr_buy=0,curr_sell=0,ahead_buy=0,ahead_sell=0;
        
        for(int ind=n-1;ind>=0;ind--)
        {
            
           curr_buy=max(-prices[ind]+ahead_sell,0+ahead_buy);
       
            curr_sell=max(prices[ind]+ahead_buy-fee,0+ahead_sell);
    
            ahead_buy=curr_buy;
            ahead_sell=curr_sell;
            
        }
        return ahead_buy;
    }
};