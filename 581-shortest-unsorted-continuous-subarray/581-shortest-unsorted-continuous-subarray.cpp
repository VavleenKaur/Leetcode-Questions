class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int n=nums.size();
        while(low+1<n && nums[low+1]>=nums[low]) low++;
        while(high-1>=0 && nums[high-1]<=nums[high]) high--;
        if(low==n-1) return 0;
        int minm=1e9,maxm=-1e9;
        for(int i=low;i<=high;i++)
        {
            minm=min(minm,nums[i]);
            maxm=max(maxm,nums[i]);
        }
        while(low-1>=0 && nums[low-1]>minm) low--;
        while(high+1<n && nums[high+1]<maxm)high++;
        return high-low+1;
    }
};