class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int count=0;
        int cur_sum=0;
        for(int i=0;i<nums.size();i++)
        {
           cur_sum+=nums[i];
            //prefix sum
            if(cur_sum==k)
            {
                count++;
            }
           if(m.find(cur_sum-k)!=m.end())
           {
               count+=m[cur_sum-k];
           }
           m[cur_sum]++;
        }
        return count;
    }
};