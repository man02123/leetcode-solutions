class Solution {
public:
    int distanceTraveled(int m, int ad) {
        
        int ans = 0;
        while(m>0 ){
            
            if(m>4 && ad>0)
            {
                ans+=50;
                m-=5;
                if(ad==0)
                    return ans+m*10;
                if(ad>0)
                {
                    m+=1;
                    ad--;
                }
            }
            else if(m<5)
                return ans+m*10;

          if(ad==0)
              return ans+10*m;
            
        }
        return ans;
        
    }
};