class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> mp;
        
        int n  =s.size();
        
        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                
                string x = s.substr(i,j-i+1);
                mp[x]++;
            }
        }
    int ans = -1;
        
        for(auto it:mp){
            if(it.second >2){
                
               
                bool  x = true;
                string z = it.first;
                vector<int> temp(26);
                
                char y = z[0];
                
                for(int i =0;i<z.size();i++){
                    if(z[i] != y){
                        x = false;
                        break;
                    }
                }
                int v  = z.size();
                if(x)
                ans= max(ans ,v);
            }
        }
        
        return ans;
    }
};