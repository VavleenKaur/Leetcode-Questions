class Solution {
public:
    // bool compr(string &a, string &b)
    // {  unordered_set<char> seta,setb;
    //     for (int i = 0; i < a.size(); i++){
    //     seta.insert(a[i]);
    //    }
    //     for (int i = 0; i < b.size(); i++){
    //     setb.insert(b[i]);
    //    }
    //    if(seta.size()==setb.size()) return true;
    //    return false;
    // }
    
    
    int numSplits(string s) {
        int n=s.size();
        int ans=0;
        // int i=0,j=n-1;
        // for(int k=i;k<j;k++)
        // {   string a=s.substr(i,k+1);
        //     string b=s.substr(k+1,j+1);
        //     cout<<a<<"___"<<b<<endl;
        //    ans+=compr(a,b);//partition
        // }
        // return ans;
        unordered_set<char>left,right;
        vector<int>prefix(n,0),suffix(n,0);
        for(int i=0;i<n;i++)
        {
            left.insert(s[i]);
            prefix[i]=left.size();
            right.insert(s[n-i-1]);
            suffix[n-i-1]=right.size();
        }
        for(int i=0;i<n-1;i++)
        {
            if(prefix[i]==suffix[i+1])
            {
                ans++;
            }
        }
       return ans; 
    }
};