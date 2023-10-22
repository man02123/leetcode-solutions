class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> st;
        vector<int> ans;
        st.push({t.back(),t.size()-1});
            ans.push_back(0);
        
        for(int i = t.size( )-2;i>=0 ;i--){
            
            if(st.size() == 0){
                st.push({t[i],i});
                ans.push_back(0);
            }
            else{
                while(st.size() > 0 && st.top().first <= t[i])
                    st.pop();
                
                if(st.size() == 0){
                st.push({t[i],i});
                ans.push_back(0);
                }
                else{
                   
                    ans.push_back(st.top().second-i);
                     st.push({t[i],i});
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};