class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s == "")return 0;
        int ans = 1;
        
        unordered_set<char> st;
        int j = 0;
        
        for(int i = 0;i<s.size();i++){
            
            if(st.find(s[i]) == st.end()){
                ans = max(ans , i+1-j);
        
            }
            
            while(j<i && st.find(s[i]) != st.end()){
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
        }
        return ans;
        
    }
};