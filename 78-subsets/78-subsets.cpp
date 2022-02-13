class Solution {
public:
    vector<vector<int>> subset;

    vector<vector<int>> subsets(vector<int>& nums) {
           int i=0;
        vector<int>v;
        recursion(i,nums,v);
        return subset;
    }
    void recursion(int i,vector<int>&nums,vector<int>&v)
    {
        subset.push_back(v);
        for(;i<nums.size();i++)
        {v.push_back(nums[i]);
        recursion(i+1,nums,v);       
        v.pop_back();
        }
    }
};