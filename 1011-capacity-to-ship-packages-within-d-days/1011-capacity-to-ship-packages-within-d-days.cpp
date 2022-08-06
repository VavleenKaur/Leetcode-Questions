class Solution {
public:
    int findMinCapacity(int mid,vector<int>&weights,int days)
    {
        int res=0,sum=0;
        for(int i=0;i<weights.size();i++)
        {   if(sum+weights[i]>mid)
             {
                res++;
                sum=0;
             }
            
            sum+=weights[i];
        }
        if(sum<=mid) res++;
        return res;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int left=*max_element(weights.begin(),weights.end());
        int right=1000000;
        int mid=0;
        while(left<=right)
        {   mid=left+(right-left)/2;
            if(findMinCapacity(mid,weights,days)>days)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return left;
    }
};