class Solution {
public:
    int f(int ind,vector<int>&arr)
    {
        if(ind==0 || ind==1) return ind;
        arr[0]=0;
        arr[1]=1;
        if(arr[ind]!=0) return arr[ind];
       return arr[ind]=f(ind-1,arr)+f(ind-2,arr);
    }
    int fib(int n) {
       vector<int>arr(n+1,0);
        return f(n,arr);
    }
};