class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int res=0;
        int fmax=0;
        
        unordered_map<char,int> mp;
        int i=0;
        
        for(int j=0;j<s.size();j++)
        {
            mp[s[j]]++;
            fmax=max(fmax,mp[s[j]]);
            if(j-i+1-fmax<=k)
            { res=max(res,j-i+1);
                continue;
            }
            
            mp[s[i++]]--;
            
        }
        return res;
        
    }
};