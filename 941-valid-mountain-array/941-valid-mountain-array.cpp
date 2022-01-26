class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
     if(arr.size()<3)
     {
         return false;
     }
    int max_index=max_element(arr.begin(),arr.end())-arr.begin();
        if(max_index==0 || max_index==arr.size()-1)
        {
            return false;
        }
    for(int i=1;i<=max_index;i++)
    {
        if(arr[i]<=arr[i-1])
        {
            return false;
        }
    }
    for(int i=max_index;i<arr.size()-1;i++)
    {
        if(arr[i]<=arr[i+1])
        {
            return false;
        }
    }
        return true;
    }
};