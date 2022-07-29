class Solution {
public:
    bool dfscycle(int node, vector<int>&visited,vector<int>&dfs_visited,vector<int>adj[])
    {
        visited[node]=1;
        dfs_visited[node]=1;
        for(auto l:adj[node])
        {
            if(!visited[l])
            {
                if(dfscycle(l,visited,dfs_visited,adj)) return true;
            }
            else if (dfs_visited[l])
            {
                return true;
            }
        }
        dfs_visited[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // check directed graph is cyclic or not
        int v=numCourses;
        vector<int>adj[v];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>visited(v,0);
        vector<int>dfs_visited(v,0);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
               if( dfscycle(i,visited,dfs_visited,adj)) return false;
            }
        }
        return true;
    }
};