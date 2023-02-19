class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
      vector<int> temp(26,-1);
        vector<bool> mp(26,0);
        
        for(auto it:s)
            mp[it-'a']=true;
        
        for(int i=0;i<s.size();i++)
        {
            if(temp[s[i]-'a']==-1)
                temp[s[i]-'a']=i;
            else 
            {
                temp[s[i]-'a']=i-1-temp[s[i]-'a'];
            }
        }
        for(int i=0;i<26;i++)
            if(mp[i]==false)
                temp[i]=d[i];
        
        // for(auto it:temp)
        //     cout<<it;
       
        
            
        return (temp==d);
    }
};