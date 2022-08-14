class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int k){
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size()-1;i++)
        { 
            for(int j=i+1;j<=nums.size()-1;j++)
        {   
                long long  target =(nums[i]+nums[j]);
            int left=j+1;
            int right=nums.size()-1;
            while(left<right)
            {   long long two_sum=nums[left]+nums[right];
                if(two_sum + target == k)
                {
                    vector<int>v;
                    v={nums[i],nums[j],nums[left],nums[right]};
                    res.push_back(v);
                    int nums2=nums[left];
                    int nums3=nums[right];
                    
                    while(left<right && nums[left]==nums2)left++;
                    while(left<right && nums[right]==nums3) right--;
                }
                else if(two_sum + target <k)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
                while(j+1<nums.size()&& nums[j+1]==nums[j]) j++;
            }
            while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};