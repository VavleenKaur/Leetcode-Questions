class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<double,int>>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        
        vector<double>dist(n,INT_MIN);
        priority_queue<pair<double,int>,vector<pair<double,int>>>pq;
        pq.push({1,start});
        dist[start]=1;
        while(!pq.empty())
        {
            int curr_node=pq.top().second;
            double curr_prob=pq.top().first;
            pq.pop();
            
            for(auto it:adj[curr_node])
            {
                int next_node=it.second;
                double next_prob=it.first;
               // cout<<next_prob<<" ";
                if((curr_prob*next_prob)>dist[next_node])
                {
                    dist[next_node]=curr_prob*next_prob;
                    pq.push({dist[next_node],next_node});
                }
            }
            
        }
        if(dist[end] <0) return 0;
        else return dist[end];
    }
};