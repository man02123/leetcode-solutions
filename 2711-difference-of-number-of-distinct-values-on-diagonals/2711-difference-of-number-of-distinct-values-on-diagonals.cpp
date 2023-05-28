class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& g) {
        int m = g.size();
        int n= g[0].size();
        
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            
            for(int j = 0;j<n;j++)
            {
              int l = left(g,i,j);
                int r =right(g,i,j);
                
                ans[i][j] =abs(l-r);
               
                
            }
        }
        return ans;
        
    }
    int left(vector<vector<int>>& g,int r,int c)
    {
        unordered_map<int,int> mp;
        int j =c;
        j=j-1;
        for(int i=r-1;i>=0;i--)
        {
            if(j>=0)
            {
                mp[g[i][j]]++;
                j=j-1;
            }
            
        }
        return mp.size();
    }
    int right(vector<vector<int>>& g,int r,int c)
    {
        unordered_map<int,int> mp;
        int j =c;
        j=j+1;
        for(int i=r+1;i<g.size();i++)
        {
            if(j>=0 && j<g[0].size())
            {
                mp[g[i][j]]++;
                j=j+1;
            }
            
        }
        return mp.size();
    }
};