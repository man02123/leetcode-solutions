class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
       
        for(int i=0;i<d.size();i++)
        {
                if(comp(d[i],s)==true)
                {
                    if(res.size()<d[i].size())
                        res=d[i];
                    else if(d[i]<res && res.size()==d[i].size() )
                        res=d[i];
                }
               
        }
        //cout<<comp(d[1],s);
        return res;
        
    }
    
    bool comp(string &d,string &s)
    {
        int currlen=0;
        int i=0,j=0;
        while(i<s.size())
        {
            if(s[i]==d[j])
            {
                j++;
                currlen++;
            }
            if(currlen==d.size())
                return true;
            
            i++;
        }
        return false;  
        
    }
};