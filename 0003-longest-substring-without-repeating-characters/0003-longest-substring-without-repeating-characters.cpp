class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        unordered_map<int,int> mp;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            while(j<s.size() && mp[s[j]]==0)
            {
                mp[s[j]]++;
                res=max(res,j-i+1);
                
                j++;
            }
            mp[s[i]]--;
        }
        
       return res; 
    }
};