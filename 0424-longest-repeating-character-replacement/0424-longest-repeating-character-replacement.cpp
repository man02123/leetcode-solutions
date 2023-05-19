class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;;
        
        int start = 0;
        unordered_map<char,int> mp;
        int maxfr = 0;
        
        for(int i = 0;i<s.size();i++)
        {
            mp[s[i]]++;
            maxfr = max(maxfr,mp[s[i]]);
            
            if(i-start+1-maxfr<=k)
            {
                ans = max(ans,i-start+1);
                continue;
            }
            mp[s[start++]]--;
            
        }
        return ans;
        
    }
};