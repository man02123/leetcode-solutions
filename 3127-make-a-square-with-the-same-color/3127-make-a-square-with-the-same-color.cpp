class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& g) {
        
        int res = 0;
        
         for(int i =1;i<=2;i++){
              
             for(int j =1 ;j<=2;j++){
                 int b =0, w =0;
                 if(g[i][j] == 'B')b++;
                 else w++;
                 
                 if(g[i-1][j-1] == 'B')b++;
                 else w++;
                 
                 if(g[i][j-1] == 'B')b++;
                 else w++;
                 
                 if(g[i-1][j] == 'B')b++;
                 else w++;
                 
                 if(max(b,w) >=3){
                 res =1;
             }
                 
             }
             
         }
        return res;   }
};