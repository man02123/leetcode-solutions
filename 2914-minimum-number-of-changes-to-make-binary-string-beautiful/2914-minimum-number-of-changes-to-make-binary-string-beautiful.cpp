class Solution {
public:
    int minChanges(string s) {
        
        int ans =0 ;
        for(int i =1;i<s.size();i+=2)
            if(s[i]!=s[i-1])ans++;
        
        return ans;
        
//         vector<int> pre,suf;
//         int psum =0;
//         int rsum =0;
        
//         for(int i =0;i<s.size();i++){
//           if(s[i]=='1')psum++;
//             pre.push_back(psum);
//         }
        
//         // for(int i =s.size()-1;i>=0;i--){
//         //   if(s[i]=='1')rsum++;
//         //     suf.push_back(rsum);
//         // }
//         // reverse(suf.begin(),suf.end());
        
//         int ans = INT_MAX;
//         int n = s.size();
//         for(int i=1;i<n;i+=2){
            
//             int m1l = i-psum[i];
//             int m0l = psum[i];
            
//             int m1r = (n-1-i)-;
            
//             int m0r = (n-psum)
            
            
        // }
        // return ans;
        
    }
};