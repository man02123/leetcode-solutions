class Solution {
public:
    vector<int> partitionLabels(string s) {
       unordered_map<char,int> counter;
        vector<char> visited;
        
        vector<int> res;
        for(auto it:s)
            counter[it]++;
        
        int start=0;
        
        for(int i=0;i<s.size();i++)
        {
            counter[s[i]]--;
            visited.push_back(s[i]);
            int j;
            for(j=0;j<visited.size();j++)
                if(counter[visited[j]]==0)continue;
                else
                break;
            
            if(j==visited.size())
            {
                res.push_back(i-start+1);
                start=i+1;
                visited.clear();
            }   
        }
        
        
      return res  ;
    }
};