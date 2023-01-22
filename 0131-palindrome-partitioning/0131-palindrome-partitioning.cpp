class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) { 
        vector<string> temp1;
        
      solve(s,0,temp1);
        return res;
        
    }
    void solve(string &s,int i,vector<string> &temp)
    {
        if(i==s.size())
        {
            res.push_back(temp);
            return;
        }
       
        for(int p=i;p<s.size();p++)
        {
             if(ispal(s,i,p)==true) 
             {
                 temp.push_back(s.substr(i,p-i+1));
                 solve(s,p+1,temp);
                 temp.pop_back();     
             }
        } 
    }
    
    bool ispal(string &s,int i,int j)
    {
        while(i<=j)
            if(s[i++]!=s[j--])return false;
        return true;
    }
  
};