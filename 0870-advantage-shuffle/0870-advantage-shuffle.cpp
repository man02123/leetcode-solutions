class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        multiset<int> ms{nums1.begin(), nums1.end()};
        vector<int> res;
        for(int i=0;i<nums1.size();i++)
        {
           
                auto it=ms.upper_bound(nums2[i]);
             if(it==ms.end())
            {
                 int x=*ms.begin();
                 res.push_back(x);
                 ms.erase(ms.begin());
             }
            else
            {
                res.push_back(*it);
                ms.erase(it);
            }
            
        }
        return res;
        
    }
};