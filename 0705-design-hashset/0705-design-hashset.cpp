class MyHashSet {
public:int h[1000001];
    MyHashSet() { 
    memset(h,0,sizeof(h));
    }
    
    void add(int key) {
        h[key]=1;
        
    }
    
    void remove(int key) {
        h[key]=0;
    }
    
    bool contains(int key) {
        return h[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */