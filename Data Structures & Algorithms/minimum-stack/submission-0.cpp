class MinStack {
private:
    stack<int>st,min_st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int valu = min(val, (min_st.size() == 0 ? val : min_st.top() ) );
        min_st.push(valu);
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
