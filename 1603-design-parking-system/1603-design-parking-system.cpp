class ParkingSystem {
public:int b,m,s;
    int currb,currm,currs;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
        
        currb=0,currm=0,currs=0;
        
    }
    
    bool addCar(int c) {
        if(c==1)
        {
            if(currb+1>b)
                return false;
            else
            {
                currb++;
                return true;
            }
            
        }
         else if(c==2)
        {
            if(currm==m)
                return false;
            else
            {
                currm++;
                return true;
            }
            
        }
         else if(c==3)
        {
            if(currs==s)
                return false;
            else
            {
                currs++;
                return true;
            }
            
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */