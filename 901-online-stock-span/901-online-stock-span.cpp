class StockSpanner {
public:
      vector<int>v;
      stack<int>s;
        int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
            v.push_back(price);
            int res=0;
            while(!s.empty() && v[s.top()]<=v[i])
            {
                s.pop();
            }
            if(s.empty())
            {  
               
                
               res=i+1; 
                
            }
            else if (v[s.top()]>v[i])
            {  
               res= i-s.top(); 
            }
        s.push(i);
       i++;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */