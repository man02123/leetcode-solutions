class Solution {
public:
    string convertToTitle(int c) {
        unordered_map<char,int> mp;
        int i =0;
        
        for(char c ='A' ;c<='Z';c++)
            mp[i++] = c; 
        
        string ans ;
     
        while(c>0){
            c--;
            int rem = c%26;
            
            ans.push_back(mp[rem]);
            
            c = c/26;
        }
       // ans.push_back(mp[c]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};