// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    int celebrity(vector<vector<int> >& M, int n) 
    {   // step 1: push all in stack
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        while(s.size()>1)
        {
            int first=s.top();
            s.pop();
            int second=s.top();
            s.pop();
            if(M[first][second]==1 && M[second][first]==0)
            {
                s.push(second);
            }
            else
            {
                s.push(first);
            }
        }
        // last in the stack will be potential celebrity
        int potential_celeb=s.top();
        int row_zeros=0,col_ones=0;
        for(int i=0;i<n;i++)
        {
            if(M[potential_celeb][i]==0)
            {
                row_zeros++;
            }
            if(M[i][potential_celeb]==1)
            {
                col_ones++;
            }
        }
        if(row_zeros==n && col_ones==n-1)
        {
            return potential_celeb;
        }
        return -1;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends