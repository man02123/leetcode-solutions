class FrequencyTracker {
public:unordered_map<int,int> mp,mp2,mp3;
    FrequencyTracker() {
        
    }
    
    void add(int num) {
        if(mp.find(num)!=mp.end())
        {
            if(mp2[mp[num]] ==1)
            {
               mp2.erase(mp[num]); 
            }
            else if(mp2[mp[num]] >1)
                mp2[mp[num]]--;
            
            
        }
        
        mp[num]++;
        mp2[mp[num]]++;
             
        
    }
    
    void deleteOne(int num) {
        if(mp.find(num)!=mp.end())
        {
            mp2[mp[num]]--;
            
            if(mp2[mp[num]] == 0)
                mp2.erase(mp[num]);
            
            mp[num]--;
            
            if(mp[num]==0)
                mp.erase(num);
            else
             mp2[mp[num]]++;
            
        }
        
    }
    
    bool hasFrequency(int f) {
       // cout<<mp2[f];
        if(mp2.find(f)!=mp2.end())
            return true;
        return false;
        
    }
};
/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */