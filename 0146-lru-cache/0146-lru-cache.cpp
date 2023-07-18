class LRUCache {
public:
    unordered_map<int,int> mp;
    map<int,list<int>::iterator> addmp;
    
    list<int> q;
    int cap;
    int currsize;
    LRUCache(int capacity) {
        cap=capacity;
        currsize=0;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            auto itr = addmp[key];
            q.erase(itr);
            q.push_front(key);
            
            addmp.erase(key);
            addmp[key] = q.begin();
            return mp[key];
        }
        return -1;
        
    }
    
    void put(int key, int value) {
      
        if(mp.find(key) != mp.end())
        {
            auto itr = addmp[key];
            mp.erase(key);
            addmp.erase(key);
            q.erase(itr);
            currsize--;
        }
        if(currsize >= cap)
        {
            int last = q.back();
            q.pop_back();
            addmp.erase(last);
            mp.erase(last);
            currsize--;
        }
        mp[key] = value;
        q.push_front(key);
        addmp[key] = q.begin();
        currsize++;
    }
};

