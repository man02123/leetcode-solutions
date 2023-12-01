class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& w) {
        unordered_map<string,int> mp,tmap;
        for(int i =0;i<w.size();i++)mp[w[i]]++;
        
        int len = w[0].size();
        int st = 0;
        vector<int> ans;
        
        for(int i =0;i<s.size()- (w.size()*len)+1;i++){  
            
            for(int j =i;j<i+(w.size()*len);j+=len){
                string l = s.substr(j,len);
                tmap[l]++;
            }
                     bool push = true;
                    for(auto it:tmap){
                        if(mp[it.first] != it.second){
                            push = false;
                            break;
                        }
                    }
            
                     if(push)
                    ans.push_back(st);            
             
            tmap.clear();
                st = i+1;
        }
       return ans; 
    }
};
