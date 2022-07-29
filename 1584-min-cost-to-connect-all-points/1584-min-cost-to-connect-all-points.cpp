class Solution {
public:
   int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<int> key(V,INT_MAX);
        vector<bool> MST(V,false);
        key[0]=0;
        MST[0]=true;
        int sum=0; 
        int mst=1; //taking 0 at starting so no. of nodes in MST is 1
        int node = 0; // taking first node
        for(mst=1;mst<V;mst++) // if no. of nodes is equal to points it will come out from loop
        {
            int x = points[node][0];
            int y = points[node][1];
            for(int j=1;j<V;j++)
            {
                int p = points[j][0];
                int q = points[j][1];
                int dist = abs(q-y)+abs(p-x);
                if(MST[j]==false&& dist<key[j])
                {
                    key[j]=dist; // taking distance from our node 
                }
            }
            int mini = INT_MAX;
            int z = -1;
            for(int i=0;i<V;i++)
            {
                if(MST[i]==false&&key[i]<mini) // taking the minimum value from our key value vector which is not in MST
                {
                    mini = key[i];
                    z = i;
                }
            }
            MST[z]=true;
            sum+=key[z];
            node = z; // updating the node
        }
        return sum;
    }
};