class Solution {
public:
   bool dfs(int node, vector<int>&visited,vector<int>&dfs_visited,vector<int>adj[],stack<int>&s)
    {
          visited[node] = 1;
          dfs_visited[node]=1;
    for (auto it: adj[node]) {
      if (!visited[it]) {
        if(dfs(it, visited,dfs_visited, adj,s)) return true;
      }
        else if(dfs_visited[it])
        {
            return true;
        }
    }
    dfs_visited[node]=0;
    s.push(node);
       return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // dfs approach
        int v=numCourses;
        vector<int>adj[v];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>visited(v,0);
        vector<int>dfs_visited(v,0);
        vector<int>topo;
        stack<int> s;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
               if(dfs(i,visited,dfs_visited,adj,s))
               {
                    topo.clear();
                   return topo;
               }
            }
        }
        while (!s.empty()) {
            cout<<s.top();
        topo.push_back(s.top());
        s.pop();
      }
        return topo;
    }
};