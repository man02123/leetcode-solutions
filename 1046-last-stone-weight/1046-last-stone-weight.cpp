class Solution {
public:
    int lastStoneWeight(vector<int>& st) {
        if(st.size()==1)return st[0];
        
        priority_queue<int> pq;
        for(auto it:st)
            pq.push(it);
        
        int res=0;
        int y;
        while(pq.size()>1)
        {
            int y=pq.top();pq.pop();
            int x=pq.top();pq.pop();
            
            if(pq.size()==0)
                return y-x;
            
            if(x!=y)
                pq.push(y-x);
           
        }
        if(pq.size()==0)return 0;
        
        if(pq.size()==1)return pq.top();
        
        return 0;
        
        
        
    }
};