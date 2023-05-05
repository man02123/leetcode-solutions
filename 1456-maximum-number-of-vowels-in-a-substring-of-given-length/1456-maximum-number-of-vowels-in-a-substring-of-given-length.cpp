class Solution {
public:
    int maxVowels(string s, int k) {
        int vc=0;
        int res=0;
        
        for(int j=0;j<k;j++)
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
                vc++;
        res=max(res,vc);
        
        for(int i=0;i+k<s.size();i++)
        {
            if(s[i+k]=='a' || s[i+k]=='e' || s[i+k]=='i' || s[i+k]=='o' || s[i+k]=='u')
                vc++;
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                vc--;
            res=max(res,vc);
            
        }
       return res; 
        
    }
};