class Solution {
public:
    int maxScore(string s) {
        
        vector<int> on;
        int sum = 0;
        on.push_back(0);
        for(int i =0;i<s.size();i++){
            if(s[i] == '1')sum++;
            on.push_back(sum);
        }
        int ans = 0;
        for(int i =1;i<on.size()-1;i++){
            
            int z = i-on[i];
            int o = sum-on[i];
            ans = max(ans,z+o);
        }
       
        return ans;
    }
};