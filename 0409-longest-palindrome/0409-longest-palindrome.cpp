class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto it:s)
            mp[it]++;
        
        int lgoc =0;
        int reslen=0;
        
        
        for(auto it:mp)
        {
          if(it.second%2 ==0)
              reslen+=it.second;
            else
            {
                lgoc =1;
                reslen+=it.second-1;
            }
        }
        return reslen+lgoc;
    }
};