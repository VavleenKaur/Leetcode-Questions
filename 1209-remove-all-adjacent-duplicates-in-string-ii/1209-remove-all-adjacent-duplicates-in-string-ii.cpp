class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>st;
        st.push_back({'#',0});
        for(int i=0;i<s.size();i++)
        {
            if(st.back().first==s[i]) 
            {
                ++st.back().second;
            }
            else
            {
                st.push_back({s[i],1});
            }
            if(st.back().second==k)
            {
                st.pop_back();
            }
        }
        s.clear();
        for(auto c:st)
        {   
            s.append(c.second,c.first);
        }
        return s;
    }
};