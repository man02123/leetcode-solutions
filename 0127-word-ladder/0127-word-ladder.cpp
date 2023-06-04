class Solution {
public:
    int ladderLength(string b, string end, vector<string>& word) {
        unordered_map<string,bool> mp;
        for(auto it:word)
            mp[it] = false;
        
        mp[b] = true;
        
        queue<string> q;
        q.push(b);
        int ans = 0;
        
        while(q.size()>0)
        { 
            int k = q.size();
            ans++;
            while(k--)
            {
                 string s = q.front();
                if(s == end)
                    return ans;
                
                q.pop();
                
                for(auto it:word)
                {
                    if(comp(it,s) == true  && mp[it] == false)
                    {
                        q.push(it);
                        mp[it] = true;
                    }
                }
            }
            
        }
        return 0;
        
    }
 bool comp(string &a,string &b )
 {
     int cnt = 0;
     if(a.size() != b.size())
         return false;
     
     for(int i = 0 ;i<a.size();i++)
     {
         if(a[i] != b[i])
             cnt++;
         if(cnt>1)
             return false;
         
     }
     return true;
 }
};