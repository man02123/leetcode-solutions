class Solution {
public:
    string reverseWords(string s) {
        int left=0;
        int right=0;
        
        while(right<s.size())
        {
            while(right<s.size() && s[right]!=' ')
                ++right;
            
            rever(s,left,right-1);
            left=right+1;
            right=left;
       
        }
        return s;
        
    }
    void rever(string &s,int i,int j)
        {
            while(i<=j)
                swap(s[i++],s[j--]);
        }
};