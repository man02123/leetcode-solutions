class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        set<long long> s1,s2,s3;
        for(auto it:nums1)s1.insert(it);
        for(auto it:nums2)s2.insert(it);
      
        
        int c1 = 0; // uni in s1
        for(auto it:s1){
           if(s2.find(it)==s2.end()){
               c1++;
           }   
        }
        
        int c2 = 0; //uniq in s2
         for(auto it:s2){
           if( s1.find(it)==s1.end()){
               c2++;
           }
            
        }
        
        int comm = 0; // comm in s1 s2
         for(auto it:s2){
           if( s1.find(it)!=s1.end()){
               comm++;
           }
            
        }
        
        
        int n = nums1.size()/2;
        
        int a = min(c1,n);
        int b = min(c2,n);
        
        int run1 = s1.size()-comm;
        int run2 = s2.size()-comm;
         run1 = min(run1,n);
        run2 = min(run2,n);
        
        int case1 = min(n+n,(a + comm + run2));
        int case2 = min(n+n,(b + comm + run1));
   

        //int x = s1.size()+s2.size()-comm;
        int ans = max(case1,case2);
        
        
        return ans;
    }
};