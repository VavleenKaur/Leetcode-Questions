class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
       for(int i=0;i<ops.size();i++) 
       {   if(ops[i][0]=='-' && isdigit(ops[i][1]) || isdigit(ops[i][0]))
           {  int val=stoi(ops[i]);
              st.push(val);
           }
           else if(ops[i]=="C")
           {
               st.pop();
           }
           else if(ops[i]=="D")
           {
               int val=st.top()*2;
               st.push(val);
           }
           else if(ops[i]=="+")
           {
               int val1=st.top();
               st.pop();
               int val2=st.top();
               st.push(val1);
               st.push(val1+val2);
           }
       }
        int sum=0;
       while(!st.empty())
       {   sum+=st.top();
           st.pop();
       }
        return sum;
    }
};