class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        if(n==0)return t.size();
        unordered_map<char,int> mp;
        int res = 0;
        for(auto it:t)
        {
            mp[it]++;
        }
        int time = 0;
        
        priority_queue<int> pq;
        
        for(auto it:mp)
        {
            pq.push(it.second);
        }
        
    
        while(pq.size()>0)
        {
           vector<int> temp;
            int time =0;
            for(int i =0;i<n+1;i++ )
            {
               if(pq.size()>0)
               {
                   temp.push_back(pq.top()-1);
                   pq.pop();
                   time++;
               }
            }
            
            for(auto it:temp)
            {
                //it--;
                if(it>0)
                pq.push(it);
            }
            if(pq.size()==0)
                res+=time;
                else 
                res+=n+1;    
        }
        
        
      
        return res;
    }
};