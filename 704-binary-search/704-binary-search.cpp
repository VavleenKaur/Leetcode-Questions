class Solution {
public:
    int binarySearch(vector<int>& nums, int target,int left,int right)
    {   if(left>right)
    {
        return -1;
    }
        int mid=(left+right)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
     else if(nums[mid]>target)
     {
         right--;
        return binarySearch(nums,target,left,right);
     }
     else
     {
        left++;
        return binarySearch(nums,target,left,right);
     }
    }
    int search(vector<int>& nums, int target) {
      int index=binarySearch(nums,target,0,nums.size()-1);
        return index;
    }
};