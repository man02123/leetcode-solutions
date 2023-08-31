class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int row = m.size();
        int col = m[0].size();
        
        bool f_row = false;
        bool f_col = false;
        
       for(int i = 0 ; i < row;i++){
           
           if(m[i][0] == 0)
               f_col = true;
       }
        for(int i = 0 ; i < col;i++){
           
           if(m[0][i] == 0)
               f_row = true;
       }
       
       for(int i =1;i<row;i++){
           for(int j = 1;j<col;j++)
           {
               if(m[i][j] == 0){
                   
                   m[i][0]= 0;
                   m[0][j] = 0;
               }
           }
       }
        for(int i =1;i<row;i++){
           for(int j = 1;j<col;j++)
           {
               if(m[i][0]==0 ||  m[0][j] == 0){
                   
                   m[i][j] = 0;  
               }
           }
       }
        
        if(f_row == true)
        {
            for(int i = 0;i<col;i++)
                m[0][i]=0;
        }
        if(f_col == true){
            for(int i = 0;i<row;i++)
                m[i][0]=0;
            
        }
        
        
        
        
    }
};