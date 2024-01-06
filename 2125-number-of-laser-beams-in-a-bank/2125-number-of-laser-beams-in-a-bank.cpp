class Solution {
public:
    int numberOfBeams(vector<string>& b) {
        int ans = 0;
        
        int init = 0;
        for(int i =0;i<b[0].size();i++)if(b[0][i] == '1')init ++;
        
        for(int i = 1;i<b.size();i++){
            int t  = 0;
            
            for(int j = 0;j<b[i].size();j++)if(b[i][j] == '1')t++;
            
            ans += t*init;
            if(t>0)
            init=  t;
        }
        return ans;
    }
};