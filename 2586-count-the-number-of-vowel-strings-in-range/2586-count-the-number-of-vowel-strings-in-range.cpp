class Solution {
public:
    int vowelStrings(vector<string>& w, int l, int r) {
        int res=0;
        for(int i=l;i<=r;i++)
            if(check(w,i)==true)res++;
      return res;  
    }
    bool check(vector<string>& w,int ind)
    {
        bool x=(w[ind].back()=='a' ||w[ind].back()=='e' ||w[ind].back()=='i' ||w[ind].back()=='o' ||w[ind].back()=='u' );; 
            
            
            bool y=(w[ind][0]=='a' ||w[ind][0]=='e' ||w[ind][0]=='i' ||w[ind][0]=='o' ||w[ind][0]=='u' ) ;
          
            return  x&&y;
    }
};