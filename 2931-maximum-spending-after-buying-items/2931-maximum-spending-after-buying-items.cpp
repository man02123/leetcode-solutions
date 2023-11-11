class Solution {
public:
    long long maxSpending(vector<vector<int>>& v) {
        vector<int> t;
        long long ans = 0;
        for(auto it:v){
            for(auto it2:it)t.push_back(it2);
        }
        int td = (v.size()*v[0].size());
        sort(t.begin(),t.end());
        
        for(int i =t.size()-1;i>=0;i--){
            
            ans += (1LL * td*t[i]);
            td--;
        }
        return ans;
    }
};