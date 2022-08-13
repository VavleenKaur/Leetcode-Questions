class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1,num2=-1,count1=0,count2=0,n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(num1==nums[i])
            {
                count1++;
            }
            else if(num2==nums[i])
            {
                count2++;
            }
            else if(count1==0)
            {
                num1=nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                num2=nums[i];
                count2=1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0,count2=0;
        for(auto ele:nums)
        {
            if(ele==num1)
            {
                count1++;
            }
            else if(ele==num2)
            {
                count2++;
            }
        }
        vector<int>res;
        if(count1>n/3)
            res.push_back(num1);
        if(count2>n/3)
            res.push_back(num2);
        return res;
    }
};