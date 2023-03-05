class Solution {
public:
    int passThePillow(int n, int t) {
       int lvl=0;
        
       while(t>n-1)
       {
           t=(t-n)+1;
           lvl++;
       }
        if(lvl%2==0)
        return t+1;
        
        else
            return n-t;
            
        return lvl;
        
    }
};