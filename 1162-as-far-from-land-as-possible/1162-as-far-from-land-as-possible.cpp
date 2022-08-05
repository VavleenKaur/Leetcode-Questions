class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        if(q.empty() || q.size()==m*n) return -1;
        int x=0,y=0,level=-1;
        while(!q.empty())
        {  level++;
            int size=q.size();
          while(size-->0)
          { x=q.front().first;
           y=q.front().second;
           q.pop();
           for(auto it:dir)
           {
               int next_x=x+it[0];
               int next_y=y+it[1];
               if(next_x>=0 && next_y>=0 && next_x<m && next_y<n)
               {
                   if(grid[next_x][next_y]==0)
                   {
                       grid[next_x][next_y]=1;
                       q.push({next_x,next_y});
                   }
               }
           }
          } 
        }
        return level;
    }
};