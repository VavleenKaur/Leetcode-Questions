class Solution {
public:
    bool isValid(string s) {
       stack <char> sk;
        for(auto c:s)
        {
            if(c=='(' || c=='{' || c=='[')
            {
                sk.push(c);
                continue;
            }
            
            if(c==')' || c=='}' || c==']')
            {
                if(sk.empty())
                {
                    return false;
                }
            }
            
            if((c==')' && sk.top()!='(') || (c=='}' && sk.top()!='{') || (c==']' && sk.top()!='['))
            {
                return false;
            }
            
            if((c==')' && sk.top()=='(') || (c=='}' && sk.top()=='{') || (c==']' && sk.top()=='['))
            {
                sk.pop();
            }
            
        }
        return sk.empty();
    }  
};