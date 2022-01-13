class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; 
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++) 
        {
            
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
                int low=i+1,high=n-1;
                while(low<high)
            {
                if(nums[low]+nums[high]+nums[i]==0)
                {
                 result.push_back({nums[i],nums[low],nums[high]});
                  
                while(low<high && nums[low]==nums[low+1]){
                    low++;
                }
                while(low<high && nums[high]==nums[high-1]){
                    high--;
                }
                low++;
                high--;   
                }
                else if(nums[low]+nums[high]+nums[i]<0)
                {
                    low++;
                }
                else
                {
                    high--;
                }
                
            }
            
        }
        return result;
   }
};