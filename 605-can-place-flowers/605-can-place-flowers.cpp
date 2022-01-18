class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int s) {
        
        
        int count=0,n=flowerbed.size();
        if(s==0)
        {
            return true;
        }
        if(n<3)
        {
           
           if(n==1)
            {
                if(flowerbed[0]==0 && s==1)
                {return true;}
                else
                {
                    return false;
                }
            }
            else if(n==2)
            {
                if(flowerbed[0]==0 && flowerbed[1]==0 && s==1)
                {return true;}
                else
                {
                    return false;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {   if(i==0 && flowerbed[i]==0 && flowerbed[i+1]==0)
        {
            count++;
            flowerbed[i]=1;
        }
            if(i>0 && i<n-1 && flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0)
            {
                count++;
                flowerbed[i]=1;
            }
          if(i==n-1 && flowerbed[i]==0 && flowerbed[i-1]==0)
          {
              count++;
              flowerbed[i]=1;
          }
        }
        if(count<s)
        {
            return false;
        }
        else
        {
            return true;
        }
        return false;
    }
};