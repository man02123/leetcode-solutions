
#define ll long long

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        
        vector<ll> row(n,0),col(n,0);
        int rc=n,cc=n;
    
        ll res=  0;
        
        for(int i=q.size()-1;i>=0;i--)
        {
            
            int type = q[i][0];
            
            if(type==0)
            {
                
                long long val = q[i][2];
                int ind = q[i][1]; 
                
                if(row[ind])
                {
                    continue;
                }
                    row[ind]= val*cc;
                    rc--;
            }
                    
            else
            {
                long long val = q[i][2];
                int ind = q[i][1];
                
                if(col[ind])
                {
                    continue;
                }
                    col[ind]=(val)*rc; 
                    cc--;
            }
        }
            
        
        for(auto it: row)
            res+=it;
        for(auto it: col)
            res+=it;
            
        return res;
        
    }
};