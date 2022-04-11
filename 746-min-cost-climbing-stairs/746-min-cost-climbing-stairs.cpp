class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev2=cost[0],prev=cost[1];
        for(int i=2;i<n;i++)
        {
            int fs=prev+cost[i];
            int ss=prev2+cost[i];
            int curi=min(fs,ss);
            prev2=prev;
            prev=curi;
        }
        return min(prev,prev2);
        }
};