class Solution {
public:
    int countOrders(int n) {
        
    n*=2; // as each order consists of pickup and delivery services  
        long long mod = 1e9 + 7, cnt = 1, csum[n+1];
        csum[1]= 1;
        // just precomputing the cummulative sum upto new n
        for(int i = 2; i <= n; i++)
        {
            csum[i] = csum[i-1] + i;
        }
        
        // assume that there are 6 positions to place one pickup and one delivery service.
        // how many ways to make one valid order. The answer should be 15 (5+4+3+2+1).
        // if number of positions is 4, then the answer should be 6 (3+2+1).
        // and when we place a valid order( one pickup and delivery service), 
        // the number of empty position will be the previous value - 2.
        
        for(int i = 2; i <= n; i+=2)
        {
            cnt *= csum[i-1];
            cnt %= mod;
        }
        return cnt;
    }
};