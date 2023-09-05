class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
       unordered_map<int ,int> mp;
        
        
        int ans = 0;
        int n3 = nums3.size();
        int n4 = nums4.size();
        
        for(int i =0;i<nums1.size();i++){
            
            for(int j = 0;j<nums2.size();j++){
                mp[nums1[i]+nums2[j]]++;   
            }  
        }
        
         for(int i =0;i<n3;i++){
            
            for(int j = 0;j<n4;j++){
                int csum  = nums3[i]+nums4[j];
                
                if(mp.find(-1*csum) !=mp.end()){
                    ans += mp[-1*csum];
                }
            }  
        }
        return ans;
        
    }
};