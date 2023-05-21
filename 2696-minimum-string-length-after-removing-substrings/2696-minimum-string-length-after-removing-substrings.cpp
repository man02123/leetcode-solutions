class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        //itn cnt = 0;
        
        
        for(int i =0;i<s.size();i++)
        {
            if(st.size()>0 && s[i] =='D' && st.top() =='C')
            {
                st.pop();
            }
            else if(st.size()>0 && s[i] =='B' && st.top() =='A')
                st.pop();
            
            else
                st.push(s[i]);
            
            
        }
        return st.size();
        
    }
};