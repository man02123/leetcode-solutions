class Solution {
public:
    bool halvesAreAlike(string s) {
        int i,t=0;
       for(i=0;i<(s.size())/2;++i)
       {
           char ch=s[i];
           if(ch=='a' || ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'|| ch=='A' || ch=='E'|| ch=='I'|| ch=='O'|| ch=='U')
               t++;
       }
         for(i=(s.size())/2;i<s.size();++i)
       {
           char ch=s[i];
           if(ch=='a' || ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'|| ch=='A' || ch=='E'|| ch=='I'|| ch=='O'|| ch=='U')
               t--;
       }
       if(t==0)
           return true;
        
        
        return false;
    }
};