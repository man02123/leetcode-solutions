class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<long> st;
        for(auto it:s)
        {
          if(it=="+" || it=="-" || it=="*" || it=="/" )
          {
              long x=st.top();
              st.pop();
              long y=st.top();
              st.pop();
              
              if(it=="+")
              st.push(x+y);
              else if(it=="-")st.push(y-x);
              else if(it=="*")st.push(y*x);
              else if(it=="/")st.push(y/x);  
          }
            else 
            {
                long n=stoi(it);
                st.push(n);
            }
                // st.push(stoi(s[i]));
        
        }   
        
        return st.top();
    }
};