class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& v, int t) {
        
        int n = v.size();
        vector<int> ans;
        for(int i =0;i<n;i++){
            
            int a = v[i][0];
            int b = v[i][1];
            int c = v[i][2];
            int m = v[i][3];
           long long int  x = calc(a,b,10);
           
            long long int y = calc(x,c,m);
            
            if(y == t)ans.push_back(i);
        }
        return ans;
    }
    int calc(int n,int x,int mod){
       int ans = 1;
        if(x == 0)
            return 1;
        
        if(x%2 == 0){
            return (calc(n,x/2,mod)*calc(n,x/2,mod))%mod;
        }
        else{
            return (n*calc(n,x/2,mod)*calc(n,x/2,mod))%mod;
        }
    }
};