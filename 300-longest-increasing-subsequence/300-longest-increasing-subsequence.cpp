class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<int>res;
        res.push_back(nums[0]);
        int n=nums.size();
       for(int i=1;i<n;i++)
       {
           if(nums[i]>res.back())
           {
               res.push_back(nums[i]);
           }
           else if(nums[i]<res.back())
           {
               int low1 = lower_bound(res.begin(), res.end(),nums[i])-res.begin();
                 
               res[low1]=nums[i];
           }
       }
        return res.size();
    }
};