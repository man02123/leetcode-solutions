class Solution {
public:int dp[101][101][201];
    string a,b,c;
    int x,y,z;
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        a= s1,b=s2,c=s3;
        x=s1.size(),y = s2.size(),z= s3.size();
        if(z == 0)return true;
        
        return solve(0,0,0);
        
    }
    bool solve(int i1,int i2,int i3){
        
        
        if(i3 >=z && i2>=y && i1>=x ) {
            
          return true;  
        }
        if(i3>=z)return false;
        
        if(i1 >=x && i2>= y)return false;
        
       // if(clen == c.size())return true;
        if(dp[i1][i2][i3] != -1)return dp[i1][i2][i3] ;
        
        bool ans = false;
        
        if(i1<x){
            if(a[i1] == c[i3]){
                ans |= solve(i1+1,i2,i3+1);
            }
        }
        if(i2<y){
            if(b[i2] == c[i3]){
                ans |= solve(i1,i2+1,i3+1);
            }
        }
        // if(i1<x && i2<y)
        // ans |= solve(i1+1,i2+1,i3);
      return dp[i1][i2][i3] = ans;  
    }
};