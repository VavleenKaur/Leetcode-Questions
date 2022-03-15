class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        //index of those will remain which are not balancing and hence invalid
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            if(!st.empty() && s[i]==')')
            {
                if(s[st.top()]=='(')
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
            else if(st.empty() && s[i]==')')
            {
                st.push(i);
            }
        }
        while(!st.empty())
        {
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};