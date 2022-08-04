class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        int m=heights.size();
       int n=heights[0].size(); priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
       vector<int>min_heightdiff(m*n,INT_MAX);
        min_heightdiff[0]=0;
        pq.push({0,0,0});
        while(!pq.empty())
        {
            auto [height,x,y]=pq.top();
            pq.pop();
            
            if(x==m-1 && y==n-1) return min_heightdiff[x*n+y];
            for(auto it:dir)
            {
                int next_x=x+it[0];
                int next_y=y+it[1];
                
                if(next_x>=0 && next_y>=0 && next_x<m && next_y<n){
                    
                    int newmax=max(abs(heights[next_x][next_y]-heights[x][y]),height);
                    if(newmax<min_heightdiff[next_x*n +next_y])
                    {
                        min_heightdiff[next_x*n +next_y]=newmax;
                        pq.push({min_heightdiff[next_x*n +next_y],next_x,next_y});
                    }
                }
            }
        }
        return -1;
    }
};