class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size(),res=0;
        for(int i=0;i<n;i++)
        {   int smaller_left=0,bigger_left=0,smaller_right=0,bigger_right=0;
            for(int prev1=i-1;prev1>=0;prev1--)
            {
                if(rating[prev1]<rating[i])
                {
                        smaller_left++;
                }
                else if(rating[prev1]>rating[i])
                {
                        bigger_left++;
                }
            }
         
         
            for(int prev1=i+1;prev1<n;prev1++)
            {
                if(rating[prev1]<rating[i] )
                {
                       smaller_right++;
                }
             else if(rating[prev1]>rating[i])
                {
                       bigger_right++; 
                }
            }
         res+=smaller_left*bigger_right + smaller_right*bigger_left; 
        }
        
      return res;  
    }
};