class SeatManager {
public:
    bitset<100001> bs;
    SeatManager(int n) {
      bs.set();  
    }
    
    int reserve() {
        int pos = bs._Find_first();
        bs.reset(pos);
      return  pos+1;
        
    }
    
    void unreserve(int se) {
       bs.set(se-1);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */