class Solution {
public:
    int numberOfWays(string c) {
      int mod = 1e9 + 7;
      int tc =0 ;
        for(auto it:c){
            if(it == 'S')tc++;
        }
        if(tc == 0 || tc%2 != 0)return 0;
        
        vector<int> v;
        int curr = 0 ;
        int t = 0;
        for(int  i =0;i<c.size();i++){
           
            if(c[i] == 'S')curr++;
           
            if(curr == 2 && c[i] == 'P')t++;
            
            else if(curr > 2 && c[i] == 'S'){
                v.push_back(t+1);
                curr = 1,t =0;
            }
        }
        long long int ans = 1;
        for(auto it:v){
           // cout<<it;
            ans = ((ans*it)%mod)%mod;
        }
        return ans%mod;
    }
};