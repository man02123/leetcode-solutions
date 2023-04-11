class Solution {
public:
    bool rotateString(string s, string b) {
        if(s.size()!=b.size())
            return false;
        if(s==b)
            return true;
        s=s+s;
        int loc=s.find(b);
        
        if(loc<s.size())
            return true;
        
        return false;
        
    }
};