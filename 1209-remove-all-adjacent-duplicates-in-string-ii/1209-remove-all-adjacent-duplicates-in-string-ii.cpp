class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        st.push({'#',0});
        for(int i=0;i<s.size();i++)
        {
            if(st.top().first==s[i]) 
            {
                ++st.top().second;
            }
            else
            {
                st.push({s[i],1});
            }
            if(st.top().second==k)
            {
                st.pop();
            }
        }
        s.clear();
        while(!st.empty())
        {   char a=st.top().first;
            int b=st.top().second;
             st.pop();
            s.append(b,a);
        }
        reverse(s.begin(),s.end());
        return s;
    }
};