class Solution {
public:
    vector<int> res;
    
    vector<int> grayCode(int n) {

        vector<string> fin = recur(n);
        
      for(auto it:fin)
      {
          unsigned long long value = std::stoull(it, 0, 2);
          res.push_back(value);
      }
        
      
        return res;
  
    }
    vector<string> recur(int n)
    {
       if(n==1)
         return {"0","1"};
        
         vector<string> temp = recur(n-1);
         vector<string> newres;
        
        for(int i=0; i<temp.size(); i++){
            newres.push_back("0"+temp[i]);
        }
        
         for(int i=temp.size()-1; i>=0; i--){
            newres.push_back("1"+temp[i]);
             }
        
        
      return newres;
        
    }
};