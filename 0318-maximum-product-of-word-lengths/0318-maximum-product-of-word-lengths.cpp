 class Solution {
public:
    bool check(bitset<26> &c1,bitset<26> &c2)
    {
        for(int i=0;i<26;i++)
            if((c1[i] && c2[i])==true)
                return false;
        
        return true;
    }
    
    int maxProduct(vector<string>& w) {
        int res=0,n=w.size();
        vector<bitset<26>> chars(n);
        
        for(int i=0;i<w.size();i++)
        {
            for(auto &it:w[i])
                chars[i][it-'a']=1;
            for(int j=0;j<i;j++)
            {
                if(check(chars[i],chars[j])==true)
                {
                    int x=w[i].size()*w[j].size();
                    res=max(res,x);
                }
            }
        }
        return res;
        
    }
};
