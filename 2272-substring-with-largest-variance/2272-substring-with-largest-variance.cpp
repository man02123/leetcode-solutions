 class Solution {
public:
    int largestVariance(string s) {
        
        vector<int> mp(26);
        
        for(auto it:s)
            mp[it-'a']++;
               
        int ans = 0;
        
        for(char i='a' ; i<='z';i++)
        {
            for(char j='a';j<='z';j++)
            {
                if(i==j || mp[i-'a']==0 || mp[j-'a']==0)
                    continue;
                
                for(int k=1;k<=2;k++)
                {
                    int cnt1=0,cnt2=0;
                    for(auto it:s)
                    {
                        if(it==i)
                            cnt1++;
                         if(it==j)
                             cnt2++;
                        if(cnt2>cnt1)
                        {
                           cnt2=0;
                            cnt1=0;
                        }
                        if(cnt1>0 && cnt2>0)
                    {
                        ans = max(ans,cnt1-cnt2);
                    }
                        
                    }
                    
                    reverse(s.begin(),s.end());
                }
                
                
            }
        }
        
        return ans;
        
    }
};

// public:
//     int largestVariance(string s) {
//         vector<int>arr(26);
//         for(auto x:s){
//            arr[x-'a']++; 
//         }
//         int ans=0;
//         for(char i='a';i<='z';i++){
//             for(char j='a';j<='z';j++){
//                  if(j==i||arr[i-'a']==0||arr[j-'a']==0)
//                             continue;
//                 for(int k=1;k<=2;k++){
//                    int c1=0;
//                     int c2=0;
//                     for(auto x:s){
//                         if(x==i)
//                             c1++;
//                         if(x==j)
//                             c2++;
//                         if(c2>c1){
//                             c1=0;
//                             c2=0;
//                         }
//                         if(c1>0&&c2>0)
//                         ans=max(ans,c1-c2);
//                     }
//                     reverse(s.begin(),s.end());
//                 }
//             }
//         }
//         return ans;
//     }
// };