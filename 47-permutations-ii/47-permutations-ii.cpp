class Solution {
public:
    
    void f(int ind,vector<int>&nums,vector<vector<int>>&ans,set<vector<int>>&s)
    {
        if(ind==nums.size())
        {   if(s.find(nums)==s.end())
            {
                ans.push_back(nums);
                s.insert(nums);
            }
            return ;
        }
        
        
        for(int in=ind;in<nums.size();in++)
        { swap(nums[in],nums[ind]);
            f(ind+1,nums,ans,s);
         swap(nums[in],nums[ind]);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        f(0,nums,ans,s);
        return ans;
    }
};