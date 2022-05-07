// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<int>>prev(n2+1,vector<int>(n3+1,0));
    vector<vector<int>>cur(n2+1,vector<int>(n3+1,0));
    
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            for(int k=1;k<=n3;k++)
            {
                if(A[i-1]==B[j-1] && B[j-1]==C[k-1])
                {
                    cur[j][k]=1+prev[j-1][k-1];
                }
                else
                {
                    cur[j][k]=max(prev[j][k],max(cur[j-1][k],cur[j][k-1]));
                }
            }
        }
        prev=cur;
    }
    return prev[n2][n3];
}