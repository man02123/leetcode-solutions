class Solution {
public:
    bool winnerOfGame(string col) {
        int a = 0 ,b = 0;
        
        for(int i = 1;i+1<col.size();i++){
            if(col[i-1] =='A' && col[i]=='A' && col[i+1]=='A')
                a++;
            if(col[i-1] =='B' && col[i]=='B' && col[i+1]=='B')
                b++;  
        }
        return (a>b)?true:false;
        
        return true;
        
    }
};