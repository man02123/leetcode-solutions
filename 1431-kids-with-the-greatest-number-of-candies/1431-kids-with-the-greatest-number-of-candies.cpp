class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& cand, int e) {
     
        int x=*max_element(cand.begin(),cand.end());
        int mx=e+x;
        
        vector<bool> res;
        for(auto it:cand )
        {
          if(e+it>=x)
              res.push_back(1);
            else 
             res.push_back(0);   
        }
        return res;
    }
    
};