class Solution {
public:
    void make(int a,vector<int>&parent,vector<int>&size)
    {
        parent[a]=a;
        size[a]=1;
    }
    int findParent(int a, vector<int>&parent)
    {
        if(a==parent[a]) return a;
        return parent[a]=findParent(parent[a],parent);
    }
    
    void Union(int a , int b, vector<int>&size,vector<int>&parent)
    {
        a=findParent(a,parent);
        b=findParent(b,parent);
        if(a!=b)
        {if(size[a]<size[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>parent(n);
        vector<int>size(n);
        vector<vector<int>>visited(n,vector<int>(n,0));
         for(int i=0;i<n;i++)
        {   
            for(int j=0;j<n;j++)
            {
                make(i,parent,size);
                make(j,parent,size);
            }
         }
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] && !visited[i][j])
                {  
                   Union(i,j,size,parent);
                    visited[i][j]=1;
                    visited[j][i]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(i==parent[i])
            {
                count++;
            }
        }
        return count;
    }
};