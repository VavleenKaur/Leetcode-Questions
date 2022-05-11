class Solution {
public:
    
    bool bipartite(int i,int n,vector<vector<int>>&graph,vector<int>&color)
    {
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
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // bfs
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(bipartite(i,n,graph,color)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};