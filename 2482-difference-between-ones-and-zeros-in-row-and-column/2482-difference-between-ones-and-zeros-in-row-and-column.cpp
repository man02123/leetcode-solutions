class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<int> zrow(n),orow(n),zcol(m),ocol(m);
        
        for(int i =0;i<n;i++){
            int on= 0,z = 0;
            for(int j=0;j<m;j++){
                if(g[i][j] ==1)on++;
                else
                    z++;
            }
            zrow[i] = z;
            orow[i] = on;
        }
    
    
      for(int i =0;i<m;i++){
            int on= 0,z = 0;
            for(int j=0;j<n;j++){
                if(g[j][i] ==1)on++;
                else
                    z++;
            }
            zcol[i] = z;
            ocol[i] = on;
        }
    

  for(int i=0;i<n;i++){
      for(int j =0;j<m;j++){
          g[i][j] = orow[i]+ocol[j]-zrow[i]-zcol[j];
      }
  }
return g;
    }
};