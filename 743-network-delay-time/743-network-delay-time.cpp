class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<pair<int,int>>adj[n+1]; 
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        } priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>min_time(n+1,INT_MAX);
        pq.push({0,k});
        min_time[k]=0;
        
        while(!pq.empty())
        {
            int curr_node=pq.top().second;
            int curr_time=pq.top().first;
            pq.pop();
            
            for(auto it:adj[curr_node])
            {
                int next_node=it.second;
                int next_time=it.first;
                if(curr_time+next_time<min_time[next_node])
                {
                    min_time[next_node]=curr_time+next_time;
                    pq.push({min_time[next_node],next_node});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
           if(min_time[i]>=INT_MAX)
           {
               return -1;
           }
            else
            {
                maxi=(min_time[i]>maxi)?min_time[i]:maxi;
            }
        }
        return maxi;
    }
};