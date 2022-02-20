class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> intv;
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int first=INT_MIN,second=INT_MIN;
        for(int i=0;i<intervals.size();i++)
        {
            if(first<intervals[i][0]&& second<intervals[i][1])
            {
               ans++;
                first=intervals[i][0];
                second=intervals[i][1];
            }
            else
            {
                second=max(second,intervals[i][1]);
            }
        }
        return ans;
        
    }
};