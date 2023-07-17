class Solution {
public:
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& s) {
      vector<int> freq(26,0);
        
        for(auto it:l)
            freq[it-'a']++;
        
        return solve(w,s,0,freq);
        
    }
  int solve(vector<string>& w , vector<int> &s , int ind ,vector<int> &freq)
  {
      if(ind>=w.size())
          return 0;
      bool canmake  = true;
      int ans = 0;
      
      vector<int> tfreq = freq;
          for(auto it:w[ind])
          {
              if(tfreq[it-'a']<=0)
                  canmake = false;
                  
              tfreq[it-'a']--;
              ans+=s[it-'a'];
          }
      if(canmake)
      return max(ans+solve(w,s,ind+1,tfreq) , solve(w,s,ind+1,freq));
      
      
      return solve(w,s,ind+1,freq);
          
   
      
      
  }
};
