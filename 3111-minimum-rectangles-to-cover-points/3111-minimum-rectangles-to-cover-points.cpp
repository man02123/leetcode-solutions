class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& p, int w) {
        
        sort(begin(p) , end(p));
        
        long long ans = 1;
        
        vector<int> v;
        for(auto it:p)v.push_back(it[0]);
        
        
        int prev = v[0];
        
        for(int i =1;i<v.size();i++){
            
            if(v[i]-prev <= w){
                continue;
            }
            else{
                ans++;
                prev = v[i];
            }
        }
        return ans;
    }
};