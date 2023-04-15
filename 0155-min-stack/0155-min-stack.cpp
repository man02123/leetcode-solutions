class MinStack {
public:stack<int> st;
    int mn;
    MinStack() {
      mn=INT_MAX;  
    }
    
    void push(int val) {
       if(st.size()>0)
           mn=min(st.top(),val);
        else
            mn=val;
        
        st.push(val);
        st.push(mn);
    }
    
    void pop() {
        int mini=st.top();
        st.pop();
        
        int elem=st.top();
        st.pop();
        
        if(mini==elem  && st.size()>0)
            mn=st.top();
        else if(st.size()==0)
            mn=INT_MAX;
               
    }
    
    int top() {
        int temp=st.top();
        st.pop();
        int res=st.top();
        st.push(temp);
        return res;
    }
    
    int getMin() {
        return mn;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */