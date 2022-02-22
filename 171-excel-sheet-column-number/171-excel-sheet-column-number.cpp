class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum=0;
        for(int i=columnTitle.length()-1;i>=0;i--)
        { int num=columnTitle[i]-64;
          int powe=columnTitle.length()-i-1;
          int p=pow(26,powe);
          sum+=p*num;
        }
        return sum; 
    }
};