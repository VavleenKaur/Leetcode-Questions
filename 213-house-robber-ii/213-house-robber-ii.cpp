class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>temp1=nums,temp2=nums;
        temp1.pop_back(); // 0 to n-2
        temp2.erase(temp2.begin()); // 1 to n-1
        
        return max(robbery(temp1),robbery(temp2));
    }
    int robbery(vector<int>&nums)
    {
        int prev2=0,prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=prev;
            int curi=max(pick,notpick);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};