class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // bfs approach
        int v=numCourses;
        vector<int>adj[v];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>visited(v,0);
        vector<int>indegree(v,0);
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int>topo;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
               while(!q.empty())
               {
                   int node=q.front();
                   q.pop();
                   topo.push_back(node);
                   visited[node]=1;
                   for(auto it:adj[node])
                   {
                       if(!visited[it])
                       {
                           indegree[it]--;
                           if(indegree[it]==0)
                           {
                               q.push(it);
                           }
                       }
                   }
               }
            }
        }
     if(topo.size()!=v) topo.clear();
     return topo;
    }
};