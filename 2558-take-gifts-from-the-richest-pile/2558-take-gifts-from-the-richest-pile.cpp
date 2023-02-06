class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        long long res=0;
        priority_queue<long long> pq;
        for(auto it:g)
            pq.push(it);
        for(int i=0;i<k;i++)
        {
            if(pq.size()>0)
            {
                long long x=pq.top();
                    x=sqrt(x);
                    pq.pop();
                    pq.push(x);
            }
        }
        while(pq.size()>0)
            res+=pq.top(),pq.pop();
        
        return res;
            
    }
};