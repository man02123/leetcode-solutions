class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        
        vector<string >ans;
        int cptr = 0;
        int prev =-1;
        stack<int> st;
        for(int i =1;i<=n;i++){
            if(cptr < t.size() && t[cptr] == i){
                while(st.size() >0 && st.top() < i && st.top()!=prev){
                    st.pop();
                    ans.push_back("Pop");
                }
                st.push(i);
                ans.push_back("Push");
                if(cptr < t.size())
                prev = t[cptr];
                
                cptr++;
                if(cptr == t.size())
                    return ans;
            }else{
                st.push(i);
                ans.push_back("Push");
            }
        }
        return ans;
    }
};