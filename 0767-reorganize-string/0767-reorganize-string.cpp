class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int> mp;
        
        for(auto it:s)
            mp[it]++;
        priority_queue<pair<int , char>> pq;
        
        for(auto it:mp)
            pq.push({it.second , it.first});
        
        
        string res;
        while(pq.top().first > 0){

          char currChar = pq.top().second;
            
          if(res.size()>0 && currChar==res.back())
          {
              return "";
          }
              res.push_back(currChar);
              auto temp = pq.top();
              temp.first--;
              pq.pop();
              
              if(pq.size()>0 && pq.top().first>0){
                  char Next = pq.top().second;
                  auto x = pq.top();
                  pq.pop();
                  x.first--;
                  pq.push(x);
                  
                  res.push_back(Next);
              }
              pq.push(temp);
              
            
        }
       
        
        return res;
        
    }
};