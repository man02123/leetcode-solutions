class Solution {
public:
    int accountBalanceAfterPurchase(int p) {
        
        int low = (p%10);
        
        if(low>=5){
            int i=0;
            for(i =p;i<100;i++){
             if(i%10 == 0)
                 break;
            }
            
            return 100-i;
        }
        
        int i =p;
        for(i=p;i>=0;i--){
          if(i%10 == 0)
              return 100 -i;
        }
            
       return -1;
        
    }
};

//11