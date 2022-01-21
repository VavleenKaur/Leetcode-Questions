class Solution {
public:
    
    
    
    void findSubset(int ind,vector <int>&nums,vector<vector<int>>&ans,vector<int>&sb)
    {
            ans.push_back(sb);
        
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1])
            {
                continue;
            }
            sb.push_back(nums[i]);
            findSubset(i+1,nums,ans,sb);
            sb.pop_back();
        }
    }
  
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <vector<int>>ans;
        vector<int>sb;
        sort(nums.begin(),nums.end());
        findSubset(0,nums,ans,sb);
        return ans;
    }
};