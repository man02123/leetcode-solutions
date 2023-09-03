class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char , int> mp;
        
        int ans = 0;
        
        int l = 0;
        int maxi = 0;
        char c;
        
        for(int i = 0;i<s.size() ;i++){
            
            mp[s[i]]++;
            maxi = max(maxi , mp[s[i]]);
            
            int len = i-l+1;
            
            if(len - maxi <= k ){
                ans = max(len , ans);
                continue;
            }
            
           mp[s[l++]]--;
            
        }
        return ans;
        
    }
};