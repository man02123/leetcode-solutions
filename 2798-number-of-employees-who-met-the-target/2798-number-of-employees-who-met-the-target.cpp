class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& h, int t) {
        int ans = 0;
        
        for(auto it:h){
            if(it>=t)ans++;
        }
       return ans; 
    }
};