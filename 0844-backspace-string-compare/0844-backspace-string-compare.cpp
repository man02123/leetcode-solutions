class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
       stack<char> st,st2;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                if(st.size()>0)st.pop();
            }
            else
            st.push(s[i]);
        }
         for(int i=0;i<t.size();i++)
        {
            if(t[i]=='#')
            {
                if(st2.size()>0)st2.pop();
            }
            else
            st2.push(t[i]);
        }
        
        if(st==st2)return true;
        
        return false;
    }
};