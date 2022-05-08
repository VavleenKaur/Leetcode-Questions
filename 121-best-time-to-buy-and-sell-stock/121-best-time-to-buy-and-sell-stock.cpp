class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=0;
        int minm=prices[0],profit=0;
        for(int i=1;i<prices.size();i++)
        {
            cost=prices[i]-minm;
            profit=max(profit,cost);
            minm=min(minm,prices[i]);
        }
        return profit;
    }
};