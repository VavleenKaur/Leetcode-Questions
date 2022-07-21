class Solution {
public:
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
            if(!visited[i])
            {   bool flag=false;
                queue<int>q;
                q.push(i);
                visited[i]=1;
                while(!q.empty())
                {  
                    int node=q.front();
                    if(node==source ) {
                        flag=true;
                        cout<<node<<"o"<<endl;
                    }
                    q.pop();
                    for(auto it:adj[node])
                    {
                        if(!visited[it])
                        {q.push(it);
                        visited[it]=1;
                        if(flag==true &&  it==destination) {         cout<<it<<endl;
                            return true;
                                                                                             }
                    }
                    }
                }
            }
              return false;
    }
};