class Solution {
public:unordered_map<int,int> mp;
    int minCut(string s) {
      return solve(s,0,s.size()-1);  
    }
      int solve(string &s ,int start, int end)
      {
        if(end<start)
            return 0;
          
          if(mp.find(start)!=mp.end())
              return mp[start];
          
          if(pal(s,start,end)==true)
              return 0;
          int res=INT_MAX;
        for(int k=start;k<end;k++)
        {
            if(pal(s,start,k)==true)
            {
            int x=solve(s,k+1,end);
            res=min(res,x+1);
            }
            
        }
          return mp[start]=res;
     }
    
    bool pal(string &s,int start,int end)
    { 
        while(start<=end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};