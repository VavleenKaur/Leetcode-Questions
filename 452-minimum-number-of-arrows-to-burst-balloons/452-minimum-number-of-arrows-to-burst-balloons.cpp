
 bool comp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
class Solution {
public:
    
   
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrow=1;
        sort(points.begin(),points.end(),comp);
        vector <int>temp;
        temp=points[0];
        for(auto bal:points)
        {
            if(bal[0]<=temp[1])
            { 
            }
            else
            {
                arrow++;
                temp=bal;
            }
        }
        
        
        return arrow;
    }
};