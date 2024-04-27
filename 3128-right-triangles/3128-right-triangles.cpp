class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& g) {
        
        int r = g.size();
        
        vector<int> row(1001),col(1001);
        
    
            for(int j= 0;j<g[0].size();j++){
                int x = 0;
                for(int i =0;i<r;i++){
                    if(g[i][j])x++;
                }
                row[j] = (x); 
              
            }
        
           for(int j= 0;j<r;j++){
                int x = 0;
                for(int i =0;i<g[0].size();i++){
                    if(g[j][i])x++;
                }
                col[j] = (x); 
              
            }
     long long ans = 0;
        
        for(int i=0;i<r;i++){   
            
                 for(int j =0;j<g[0].size();j++){ 
                     
                     if(g[i][j]){
                         
                         if(col[i] >=2){
                             
                             if(row[j] >=1){
                                 ans += (long long)((col[i]-1)*(row[j]-1));
                             }
                             
                         }
                     }
                 }
                    
            }
           

        return ans;
    
        
    }
};