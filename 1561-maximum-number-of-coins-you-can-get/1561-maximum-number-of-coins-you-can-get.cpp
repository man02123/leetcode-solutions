class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(begin(p),end(p));
        int sum = 0;
        int cov = 0;
        for(int i = p.size()-2;i>=0 && i>cov;i-=2)
        sum += p[i],cov++;
        return sum;
    }
};