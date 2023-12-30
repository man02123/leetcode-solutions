class Solution {
public:
    bool makeEqual(vector<string>& w) {
        map<char,int> mp;
        for(auto it:w){
            for(auto it2:it)mp[it2]++;
        }
        int len = w.size();
        bool a = 1;
        
        for(auto it:mp){
            if(it.second %len != 0)a = 0;
        }
        return a;
    }
};