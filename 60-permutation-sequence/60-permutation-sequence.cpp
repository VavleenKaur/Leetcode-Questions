class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            fact*=i;
            v.push_back(i);
        }
        v.push_back(n);
        string ans="";
        k-=1;
        while(1)
        {  
            ans+=(v[k/fact])+'0';
            v.erase(v.begin()+k/fact);
            if(v.size()==0)
            {
                break;
            }
            k=k%fact;
            fact=fact/v.size();
        }
        return ans;
    }
};