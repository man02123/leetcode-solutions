class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& p) {
        sort(begin(p),end(p));
        
        int ans = 0;
        
        for(int i =1;i<p.size();i++){
            ans  = max(ans ,p[i][0]-p[i-1][0]);
        }
        return ans;
    }
};