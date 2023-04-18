class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int i=0,j=0;
        string res;
        int n=w1.size(),n2=w2.size();
        
        while(i<n && j<n2)
        {
            res.push_back(w1[i++]);
            res.push_back(w2[j++]);
        }
        while(i<n)
        {
          res.push_back(w1[i++]);  
        }
         while(j<n2)
        {
          res.push_back(w2[j++]);  
        }
        return res;
    }
};