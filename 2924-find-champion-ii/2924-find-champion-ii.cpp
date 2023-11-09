class Solution {
public:
    int findChampion(int n, vector<vector<int>>& e) {
        unordered_map<int , int> mp;
        
        for(auto it:e){
            mp[it[1]]++;
        }
        int ans = -1;
        for(int i = 0;i<=n-1;i++){
            if(mp.find(i) == mp.end() && ans == -1)
                ans = i;
            else if(mp.find(i) == mp.end() && ans != -1 && ans != i)
                return -1;
        }
        return ans;
    }
};