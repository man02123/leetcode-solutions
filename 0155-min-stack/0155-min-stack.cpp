class MinStack {
public:stack<int> st;
    int mn;
    MinStack() {
      mn=INT_MAX;  
    }
    
    void push(int val) {
       if(st.size()==0)
       {
           mn=val;
           st.push(val);
       }
        else
        {
           if(val>mn)
               st.push(val);
            else
            {
                st.push(mn);
                mn=val;
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.size()==0)
            return ;
       if(st.top()!=mn)
           st.pop();
        else
        {
            st.pop();
            if(st.size()>0)
            {
            mn=st.top();
            st.pop();
            }
        }
    }
    
    int top() {
        
        return st.top();
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