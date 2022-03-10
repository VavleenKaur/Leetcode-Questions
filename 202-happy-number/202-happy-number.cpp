class Solution {
public:
    int nextnum(int n)
    {
        int digit=0,sum=0;
         while(n!=0)
       { digit=(n%10);
         sum+=(digit*digit);
         n=n/10;
       }
        return sum;
    }
    bool isHappy(int n) {
        vector<int>vec;
        int count=0;
        while(n!=1)
        {  if( find(vec.begin(), vec.end(), n) == vec.end() )
            { 
            vec.push_back(n);
            n=nextnum(n);
            }
            else
            {
                return false;
            }
        }
        return n==1;
    }
};