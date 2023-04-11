class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int top=0;
        int r=mat[0].size()-1;
        int l=0;
        int down=mat.size()-1;
        vector<int> res;
        
        while(l<=r && top<=down)
        {
            for(int i=l;i<=r;i++)
            {
                res.push_back(mat[top][i]);
            }
            top++;
            
                for(int j=top;j<=down;j++)
                {
                    res.push_back(mat[j][r]);
                }
                r--; 
            
            if(top<=down)
            {
            for(int i=r;i>=l;i--)
            {
               res.push_back(mat[down][i]); 
            }
            }
            down--;
            
            if(l<=r)
            {
                for(int j=down;j>=top;j--)
                  res.push_back(mat[j][l]);   
            }
            l++;  
        }
        return res;
        
    }
};