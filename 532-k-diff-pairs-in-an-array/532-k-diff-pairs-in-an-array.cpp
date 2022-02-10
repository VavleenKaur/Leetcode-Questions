class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      unordered_map<int,int>m;
        if(k<0)
        {
            return 0;
        }
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            
        }
            for(auto n:m)
            {
               if((n.second>1 && !k)||(m.count(n.first+k) &&k))
               {
                   count++;
               }
            }
        
        return count;
    }
};