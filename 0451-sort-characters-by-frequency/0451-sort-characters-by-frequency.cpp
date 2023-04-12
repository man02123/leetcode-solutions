class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> m;
        for(auto it=s.begin();it!=s.end();++it)
        {
         m[((*it))]++;     
         }
         for(auto i=m.begin();i!=m.end();++i)
         {
             pq.push({i->second,i->first});
            
         }
        string f;
        while(pq.size()!=0)
        {
            for(int j=0;j<(pq.top().first);++j)
            {
                f.push_back(pq.top().second);
            }
            pq.pop();
        }
        return f;
    }
};