class Solution {
public:
    double memo(int kR, int kC,int n, vector<vector<vector<double>>>&dp,int k)
{   
    if((kR<0 || kR>=n || kC>=n || kC<0)) return 0.0;
    if(k==0 ) return 1.0;
    if(dp[kR][kC][k]!=-1) return dp[kR][kC][k];
    double nL,nR,nW,nE,sW,sE,sL,sR;
    nL=memo(kR+2,kC-1,n,dp,k-1);
    nR=memo(kR+2,kC+1,n,dp,k-1);
    nW=memo(kR+1,kC-2,n,dp,k-1);
    nE=memo(kR+1,kC+2,n,dp,k-1);
    sW=memo(kR-1,kC-2,n,dp,k-1);
    sE=memo(kR-1,kC+2,n,dp,k-1);
    sL=memo(kR-2,kC-1,n,dp,k-1);
    sR=memo(kR-2,kC+1,n,dp,k-1);
    return dp[kR][kC][k]=(nL+nR+nW+nE+sW+sE+sL+sR)/8.0;
}

    double knightProbability(int n, int k, int row, int col) {
        // col, row given
    // i+2, j+1 | i+2, j-1 | i-1, j+2| i-1,j-2 | i+1, j+2 | i+1, j-2
    vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
    //cout<<knightRow<<knightCol<<targetRow<<targetCol;
    if(k==0) return 1.0;
    if(k==1 && n==1) return 0.0;
    if(n==1) return 1.0;
    return memo(row,col,n,dp,k);
    }
};