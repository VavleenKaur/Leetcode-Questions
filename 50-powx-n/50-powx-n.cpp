class Solution {
public:
    double myPow(double x, int n) {
        double x_v=1.0;
        if(n==0) return 1;
        if(x==1) return 1;
        long long l=n;
        l=abs(n);
        while(l>0)
        {  
          if(l%2==0)
          {x*=x;
           l/=2;
          }
            else
         {
             x_v=x_v*x;
             l-=1;
         }
            
        }
        if(n>=0)
        {return x_v;}
        return 1/x_v;
    }
};