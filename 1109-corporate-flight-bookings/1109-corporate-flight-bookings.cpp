class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> res(n+1,0);
        
        for(int i = 0;i < b.size() ;i++)
        {
            res[b[i][0]-1]+=b[i][2];
            res[b[i][1]]-=b[i][2];
                
        }
        
        
        for(int i = 1;i<n;i++)
        {
            res[i] = res[i]+res[i-1];
        } 
        return {res.begin(),res.begin()+n};
    }
};