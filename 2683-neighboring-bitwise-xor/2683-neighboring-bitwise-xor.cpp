class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int x= 0;
        
        for(auto it:d)
           x^=it; 
        
        
        return x==0 ?1:0;
        
        
    }
};