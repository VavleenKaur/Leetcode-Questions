class FreqStack {
public:
     map<int, vector<int>> last_index;
    map<int, int> cnt;
    // cnt, position, value
    set<pair<pair<int, int>, int>> st;
    int index;
    
public:
    FreqStack() {
        index = 0;
    }
    
    void push(int val) {
        // erase from set
        if(cnt[val] != 0) {
            st.erase({{cnt[val], last_index[val].back()}, val});
        }
        last_index[val].push_back(index++);
        cnt[val] += 1;
        st.insert({{cnt[val], last_index[val].back()}, val});
    }
    
    int pop() {
        int val = st.rbegin()->second;
        
        st.erase({{cnt[val], last_index[val].back()}, val});
        last_index[val].pop_back();
        cnt[val] -= 1;
        if(cnt[val] > 0)
            st.insert({{cnt[val], last_index[val].back()}, val});
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */