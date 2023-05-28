class Solution {
public:
    long long minimumCost(string s) {
        long long l0=0,l1=0,r0=0,r1=0;
        int n = s.size();
       
        int fleft = 0,fright=0;
        
        for(int i=(n/2)-1;i>=0;i--) //make zero
        {
          if((s[i]=='1' && fleft%2==0) || (s[i]=='0' && fleft%2==1) )
          {
              fleft++;
              l0+=i+1;
          }     
        }
        
        
        fleft=0;
        
         for(int i=(n/2)-1;i>=0;i--) //make 1 in left
        {
          if((s[i]=='0' && fleft%2 == 0) || (s[i]=='1' && fleft%2==1))
          {
             // cout<<i;
              fleft++;
              l1+=i+1;
          }     
        }
        
         for(int i=(n/2);i<n;i++) //make 0 in right
        {
          if((s[i]=='1' && fright%2==0) || (s[i]=='0' && fright%2==1))
          {
              fright++;
              r0+=n-i;
          }     
        }
        fright=0;
          for(int i=(n/2);i<n;i++) //make 1 in right
        {
          if((s[i]=='0' && fright%2==0) || (s[i]=='1' && fright%2==1))
          {
              fright++;
              r1+=n-i;
          }     
        }
        
       //cout<<l0<<l1<<r0<<r1;
        
        
        return min(l0+r0,l1+r1);
        
    }
};