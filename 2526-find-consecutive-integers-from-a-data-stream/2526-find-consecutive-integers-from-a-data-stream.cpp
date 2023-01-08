class DataStream {
public:
    int totalsize;
    int val;
    int count;
    DataStream(int value, int k) {
        val=value;
        totalsize=k;
        count=0;
        
    }
    
    bool consec(int num) {
        
       if(num==val) count++;  
        
        if(num!=val)count=0;
        if(count>=totalsize)return true;
        
        return false;
        
        
        
       
        
    }
    
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */