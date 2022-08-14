class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int len=0,maxLen=0;
        for(auto it:s)
        {   len=0;
            if(s.count(it-1)) continue;
                len++;
                int j=1;
                while(s.count(it+j))
                {   j++;
                    len++;
                }
               maxLen=max(maxLen,len);
        }
        return maxLen;
    }
};