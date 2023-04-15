class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.size()==0 ||  s[i]=='(' || s[i]=='{' || s[i]=='[' )
            st.push(s[i]);
            
            else if (st.size()>0 )
            {
                if((st.top()=='(' && s[i]==')')  ||  (st.top()=='{' && s[i]=='}') ||
              (st.top()=='[' && s[i]==']'))
                st.pop();
                else if((st.top()!='(' && s[i]==')')  ||  (st.top()!='{' && s[i]=='}') ||
              (st.top()!='[' && s[i]==']'))
                    return false;
            } 
               
        }
        return (st.size()==0);
        
    }
};