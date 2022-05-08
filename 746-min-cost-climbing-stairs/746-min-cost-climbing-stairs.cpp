class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev2=cost[0],prev=cost[1];
        for(int i=2;i<n;i++)
        {
            int f=prev2+cost[i];
            int s=prev+cost[i];
             int cur=min(f,s);
            prev2=prev;
            prev=cur;
        }
        return min(prev2,prev);
    }
};