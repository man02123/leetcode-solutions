class Solution {
public:
    string sortVowels(string s) {
        set<char> st ={};
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        
        vector<char> ans(s.size(),'#');
        vector<char> t;
        
        for(int i =0;i<s.size();i++){
            
            if(st.find(s[i]) == st.end())
            ans[i] = s[i];
            
            else
                t.push_back(s[i]);

        }
        sort(t.begin(),t.end());
        int k =0;
        
        for(int i =0;i<s.size();i++){
            if(ans[i] == '#')
                ans[i] = t[k++];
                
        }
        string a;
        
        for(auto it:ans)
            a.push_back(it);
        
        return a;
        
        
        
        
    }
   
};