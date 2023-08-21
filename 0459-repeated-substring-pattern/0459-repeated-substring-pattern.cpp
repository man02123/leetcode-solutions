class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=1;i<=n/2;i++)
        {
           string temp;
            temp= s.substr(0,i);
            int k=temp.size();

            if(n%(k)!=0)continue;
           else 
           {
             int numtimes=(n/k);
               string res;
               while(numtimes!=0)
               {
                   res+=temp;
                   numtimes--;
               }
               
//                for(auto it:res)cout<<it;
               if(res==s)return true;
               
           }
    
        }
        return false;
        
    }
};