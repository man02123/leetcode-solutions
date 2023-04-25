class Solution {
public:
    int hammingDistance(int x, int y) {
       int xr = x^y;
        int res=0;
        int i=0;
           while(i<32)
           {
               int bit=xr>>i;
               
               i++;
               res+=bit&1;
           }
      
        return res;
    }
};