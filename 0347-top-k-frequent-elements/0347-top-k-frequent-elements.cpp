class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
         for(int i=0;i<nums.size();i++)
         {
          m[nums[i]]++;
         }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(auto j= m.begin();j!=m.end();j++)
        {
         p.push({j->second,j->first});
             if(p.size()>k)
                 p.pop();
        }
        vector<int> v;
        while(p.size()!=0)
        {
          v.push_back(p.top().second);
            p.pop();
     
        }
        return v;
        
            
        
    }
};