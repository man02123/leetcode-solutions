class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        if(k==1)return nums;
        
        bool flag=false;
        q.push_back(nums[0]);
        
        for(int i=0;i+k-1<nums.size();i++)
        {
            int j=1;
            while(j<k-1 && flag==false)
            {
              while( q.size()>0 && q.back()<nums[j]) 
                  q.pop_back();
                
                q.push_back(nums[j]);
                j++;
            }
            flag=true;
            
            while(q.size()>0 && q.back()<nums[i+k-1])
                q.pop_back();
            
            q.push_back(nums[i+k-1]);
            
             res.push_back(q.front());
            
            if(q.front()==nums[i])
                q.pop_front();
              
            
        }
        
      
     return res;  
    }
};