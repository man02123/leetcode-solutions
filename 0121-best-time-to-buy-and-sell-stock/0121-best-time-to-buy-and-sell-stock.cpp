class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans  = 0;
        int cmin = INT_MAX;
        int n = p.size();
        
        for(int i = 0;i<n;i++){
            
            ans = max(ans , (p[i]-cmin));
            cmin = min(cmin , p[i]);
            
        }
        return ans;
    }
};