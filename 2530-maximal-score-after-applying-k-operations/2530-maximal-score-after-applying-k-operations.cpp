class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(auto it:nums)pq.push(it);
        long long score=0;
        
        while(pq.size()>0 && k>0)
        {
            long long x=pq.top();
            score+=pq.top();
            pq.pop();
           if(x%3>0)
               x=x/3+1;
            else
             x=x/3   ;
            pq.push(x);
            k--;
        }
        return score;
        
    }
};