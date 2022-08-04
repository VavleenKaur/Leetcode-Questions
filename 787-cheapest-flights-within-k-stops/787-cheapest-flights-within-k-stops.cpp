class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<tuple<int,int>>adj[n];
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<int>min_price(n,INT_MAX);
        pq.push({0,src,0});
        min_price[src]=0;
        vector<int>present_stops(n,INT_MAX);
        present_stops[src]=0;
        while(!pq.empty())
        {
            auto [curr_price, curr_node, curr_stops]=pq.top();
            pq.pop();
            
            if(curr_node==dst) return curr_price;
            if(curr_stops==k+1) continue;
            for(auto it:adj[curr_node])
            {
               
                auto [next_node,next_price]=it;
                if(next_price+curr_price<min_price[next_node] || curr_stops+1<present_stops[next_node])
                {
                  min_price[next_node]=next_price+curr_price;
                        present_stops[next_node]=curr_stops+1;
                        cout<<next_node<<" "<<min_price[next_node]<<" "<<present_stops[next_node]<<"  "<<curr_node<<" "<<present_stops[curr_node]<<endl; 
                        pq.push({min_price[next_node],next_node,present_stops[next_node]});
                    }
                }
            }
        
       return -1;
        
        
    }
};