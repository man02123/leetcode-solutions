class Solution {
public:string ans;
    vector<int> dx;
    vector<int> dy;
    bool exist(vector<vector<char>>& b, string word) {
        ans=word;
        dx={0,1,-1,0};
        dy={1,0,0,-1};
        bool t=false;
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<b[0].size();j++)
            {
                if(b[i][j]==ans[0])
                    t|=recur(b,i,j,0);
                    
            }
        }
        return t;
    }
    bool recur(vector<vector<char>>& b,int r,int c,int ind)
    {
        if(ind==ans.size())
            return true;
        
        if(r>=b.size() || r<0 || c>=b[0].size() || c<0 || b[r][c]=='1' || b[r][c]!=ans[ind])
            return false;
        
        bool res=false;
        
        for(int i=0;i<4;i++)
        {
            char x= b[r][c];
            b[r][c]='1';
            int nx=r+dx[i];
            int ny = c+dy[i];
           
            res|=recur(b,nx,ny,ind+1);
            
            b[r][c]=x;
 
        }
        return res;
    }
};