class SmallestInfiniteSet {
public:unordered_map<int,int> mp;
    priority_queue<int,vector<int>,greater<int>> pq;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {
            pq.push(i);
            mp[i]++;
        }
    }
    
    int popSmallest() {
        if(pq.size()>0)
        {
            int x = pq.top();
            mp[x]--;
            pq.pop();
            if(mp[x]==0)
                mp.erase(x);
            return x;
        }
       return -1; 
    }
    
    void addBack(int num) {
        if(mp.find(num)!=mp.end())
            return;
        
        pq.push(num);
        mp[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */