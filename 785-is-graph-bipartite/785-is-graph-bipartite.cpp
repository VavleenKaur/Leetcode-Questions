class Solution {
public:
    
   /* bool bipartite(int i,int n,vector<vector<int>>&graph,vector<int>&color)
    { //bfs
        queue<int>q;
        q.push(i);
        color[i]=1;
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(auto it:graph[f])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[f];
                    q.push(it);
                }
                else if(color[it]==color[f])
                {
                    return false;
                }
            }
        }
        return true;
    }*/
    
    bool bipartite(int i,vector<vector<int>>&graph,vector<int>&color)
    {
       //dfs
        for(auto it:graph[i])
        {
            if(color[it]==-1)
            {   color[it]=1-color[i];
                if(bipartite(it,graph,color)==false) return false;
            }
            else if(color[i]!=-1 && color[it]==color[i])
            {
                return false;
            }
        }
        return true;
    }
   
    bool isBipartite(vector<vector<int>>& graph) {
      
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {   color[i]=1;
                if(bipartite(i,graph,color)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};