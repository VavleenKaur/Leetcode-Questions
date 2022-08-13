class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        if(intervals.size()<=1) return intervals;
        vector<vector<int>> merged;
        vector<int>interval=intervals[0];
        for(auto it:intervals)
        {
            if(it[0]<=interval[1])
            {
                interval[1]=max(it[1],interval[1]);
                
            }
            else
            {
                merged.push_back(interval);
                interval=it;
            }
        }
        merged.push_back(interval);
        return merged;
    }
};