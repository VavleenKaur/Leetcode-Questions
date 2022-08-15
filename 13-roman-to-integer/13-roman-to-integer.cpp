class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int sum=mp[s[s.size()-1]];
        for(int i=s.size()-1;i>0;i--)
        {
            if(mp[s[i-1]]>=mp[s[i]])
            {  
                sum+=mp[s[i-1]];
                
            }
            else
            {
                sum-=mp[s[i-1]];
            }
        }
        return sum;
    }
};