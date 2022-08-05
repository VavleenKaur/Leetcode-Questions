class Solution {
public:
    long long int findTotal(int k,vector<int>&piles,int h)
    {   long long int res=0;
        for(int i=0;i<piles.size();i++)
        {       if(piles[i]>k)
        {res+=piles[i]/k;
         if(piles[i]%k!=0)
         {
             res++;
         }
        }
             else{
                    res++;
                }
        }
     return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size()<1) return 0;
        int maxi=*max_element(piles.begin(),piles.end());
        int len=piles.size();
        if(len==h) return maxi;
        int left=1,right=maxi;
        int mid=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(findTotal(mid,piles,h)>h) {
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