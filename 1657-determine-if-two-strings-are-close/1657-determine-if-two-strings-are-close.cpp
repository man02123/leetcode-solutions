class Solution {
public:
    bool closeStrings(string w1, string w2) {
        unordered_map<char,int> mp1,mp2;
        if (size(w1)!=size(w2))return false;
      
        
        for(auto it:w1)mp1[it]++;
      for(auto it:w2)mp2[it]++;
        
        vector<int> v1,v2;
        vector<char>v3,v4;
        
        for(auto it:mp1)
        {
            v3.push_back(it.first);
            v1.push_back(it.second);
        }
        for(auto it:mp2)
        { v2.push_back(it.second);
           v4.push_back(it.first);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());
        sort(v4.begin(),v4.end());
        if(v1==v2 && v3==v4)return true;
        return false;
    }
};