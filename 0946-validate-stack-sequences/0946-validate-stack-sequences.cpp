class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        stack<int> st;
        int i=0,j=0;
        
        for(auto it:pu)
        {
            st.push(it);
            while(st.size()>0 && j<po.size() && st.top()==po[j])
                st.pop(),j++;
            
            // if(st.size()>0 && st.top()==po[j])
            // {
            //     st.pop();
            //     j++;
            // }
            // else if(st.size()==0 && j<po.size())
            //     return false;
        }
        return j==po.size();
        
       
    }
};