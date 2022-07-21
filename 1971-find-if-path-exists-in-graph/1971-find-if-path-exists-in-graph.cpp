class Solution {
public:
    
    void dfs(int i, vector<int>&visited , vector<int> adj[],int dest,int source)
    {
        visited[i]=1;
        for(auto it:adj[i])
        {   if(!visited[it])
            { dfs(it,visited,adj,dest,source);}
        }
    
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1) return true;
        if(source==destination) return true;
       vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {  if((edges[i][0]==source && edges[i][1]==destination) || (edges[i][0]==destination && edges[i][1]==source)) return true;
          //cout<<edges[i][0]<<edges[i][1]<<endl;
          adj[edges[i][0]].push_back(edges[i][1]);
          adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n,0);
        int i=source;  
     dfs(i,visited,adj,destination,source);
        return visited[destination];
    }
                
};