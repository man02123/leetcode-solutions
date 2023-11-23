class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
//         if(nums1.size() != nums2.size()){
            
//         }
        
        
        
        int max1 = nums1.back();
        int max2 = nums2.back();
        
        vector<int>t1 = nums1,t2 = nums2;
        int op1= 0,op2 = 0;
        int sz = min(nums1.size() ,nums2.size());
        sz--;
        int sz2 = sz;
        if(t1.back() < t2.back()) {
            op1++;
            swap(t1.back(),t2.back());
            max1 = t1.back();
            max2 = t2.back();
        }
                                               
        for(int i =t1.size()-2;i>=0;i--){
             
            if(t2[i] > max2 && sz >0){
                swap(t2[i],t1[i]);
                op1++;
            }
            sz--;
        }
        bool op1valid = true;
        for(int i =0;i<t1.size();i++){
            if(t1[i] <= t1.back())continue;
            else
                op1valid = false;
        }
        for(int i =0;i<t1.size();i++){
            if(t2[i] <= t2.back())continue;
            else
                op1valid = false;
        }
        int ans = INT_MAX;
        if(op1valid)
            ans = op1;
        
        
        // case 2
        if(nums1.back() > nums2.back()){
            swap(nums1.back() ,nums2.back());
            op2++;
        }
        max1 = nums1.back();
        max2 = nums2.back();
        
        
         for(int i =nums1.size()-2;i>=0;i--){
             
            if(nums1[i] > max1 && sz2>0){
                swap(nums1[i],nums2[i]);
                op2++;
            }
           sz2--; 
        }
        bool op2valid = true;
        for(int i =0;i<nums1.size();i++){
            if(nums1[i] <= nums1.back())continue;
            else
                op2valid = false;
        }
        for(int i =0;i<nums1.size();i++){
            if(nums2[i] <= nums2.back())continue;
            else
                op2valid = false;
        }
        
        if(op2valid)
            ans = min(ans,op2);
        
        if(ans == INT_MAX)return -1;
        
        
        
        return ans;
        
    }
};