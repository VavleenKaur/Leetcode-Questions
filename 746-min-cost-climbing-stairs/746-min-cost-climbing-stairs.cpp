class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n<=1)
        {
            return n?cost[0]:0;
        }
        int prev2=cost[0];
        int prev=cost[1];
        for(int i=2;i<n;i++)
        {
            int f_step=prev2+cost[i];
            int s_step=prev+cost[i];
            int curr=min(f_step,s_step);
            prev2=prev;
            prev=curr;
        }
        return min(prev,prev2);
    }
    // int memo(vector<int>& cost,int ind)
    // {
    //    if(ind==0 || ind==1) return cost[ind];
    //     int oneStep=0,twoStep=;
    //     oneStep=memo(cost,ind-1)+abs(cost[ind]);
    //     twoStep=memo(cost,ind-2)+abs(cost[ind]);
    //     return min(oneStep,twoStep);
    // }
};