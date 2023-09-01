class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i = 1;i<=n ;i++){
            res.push_back(solve(i));
        }
        return res;
    }
    int solve(int num){
        if(num == 1)
            return 1;
        
        if(num%2 == 0)
            return solve(num/2);
        else
            return 1+solve(num/2);
    }
};