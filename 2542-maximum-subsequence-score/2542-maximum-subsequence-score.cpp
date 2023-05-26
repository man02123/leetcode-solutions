class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        long long res1 = 0,sum1 = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<pair<int,int>> v;
        
        for(int i =0;i<nums1.size();i++)
            v.push_back({nums2[i],nums1[i]});
        
        
        sort(v.rbegin(),v.rend());
        
        for(int i =0;i<k-1; i++)
        {
            pq.push(v[i].second);
            sum1+= v[i].second;
        }
        
        
       for(int i =k-1;i<nums1.size();i++)
       {
           pq.push(v[i].second);
           sum1 += v[i].second;
        
           long long ans = sum1*v[i].first;
           
           sum1-=pq.top();
           //cout<<pq.top();
           pq.pop();
            
            res1 = max(res1,ans);
            
        }
        

      return res1; 
    }
};
