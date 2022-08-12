class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int>prev(1,1);
        vector<int>curr(1,1);
        for(int i=0;i<=rowIndex;i++)
        { 
            curr.resize(i+1);
            curr[0]=curr[i]=1;
            for(int j=1;j<i;j++)
            {
              curr[j]=prev[j-1]+prev[j];  
            }
            prev=curr;
        }
        return prev;
    
    }
};