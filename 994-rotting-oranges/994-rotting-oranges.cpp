class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int flag=true;
        if(q.empty()) flag=false;
        int level=-1;
        while(!q.empty())
        {
            level++;
            int size=q.size();
            while(size-->0)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto it: dir )
                {
                    int next_x=x+it[0];
                    int next_y=y+it[1];
                    if(next_x>=0 && next_y>=0 && next_x<m && next_y<n)
               {
                    if(grid[next_x][next_y]==1)
                    {
                        grid[next_x][next_y]=2;
                        q.push({next_x,next_y});
                    }
                }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        if(!flag) return 0;
        return level;
    }
};