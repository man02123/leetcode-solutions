class Solution {
public:
    int beautySum(string s) {
        int res=0;
        
        
        for(int i=0;i<s.size();i++)
        {
            unordered_map<char,int> mp;
            
            for(int j=i;j<s.size();j++)
            {
                int fmax=0,fmin=501;
               mp[s[j]]++;
                for(auto it:mp)
                {
                fmax=max(it.second,fmax);
                fmin=min(it.second,fmin);
                }
                res+=(fmax-fmin);
                //fmax=0,fmin=500;
            }
            mp.clear();
        }
        return res;
        
    }
};

// class Solution {
// public:
//     int beautySum(string s) {
//         int n=s.size(),ans=0,mn=500,mx=0;
//         for(int i=0;i<n;i++){
//                 map<char,int>mp;
//             for(int j=i;j<n;j++){
//                 mp[s[j]]++;
//                 for(auto& it:mp){
//                     mn=min(mn,it.second);
//                     mx=max(mx,it.second);
//                 }
//                 ans+=(mx-mn);
//                 mn=500;mx=0;
//             }
//             mp.clear();
//         }
//     return ans;
//     }
// };