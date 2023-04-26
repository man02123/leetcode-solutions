class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
      
        deque<int> q;
        int n = arr.size();
        int j = 0;
        vector<int> res;
       
        while(j<n && j<k)
        {
            while(q.size()>0 && arr[q.back()]<=arr[j])
            q.pop_back();
            
            
            q.push_back(j);
            j++;
        }
        
        res.push_back(arr[q.front()]);
        
        for(int i=j;i<n;i++)
        {
            while(q.size()>0 && q.front()<=i-k)
            {
                q.pop_front();
            }
            while(q.size()>0 && arr[q.back()]<arr[i])
            q.pop_back();
            
            q.push_back(i);
            
            
            res.push_back(arr[q.front()]);
            
            
        }
        return res;
    }
    
};