class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> vis(s.size(),0);
        
        
        
        
        
        for(int i = 0;i<s.size();i++)
        {
            if(vis[i]==0)
            {
            for(int j=0;j<i;j++)
            {
                if(vis[j]==0 && s[j] == s[i])
                {
                    vis[j]=1;
                    break;
                }
            }
                
            for(int r=i+1;r<s.size();r++)
            {
                 if(vis[r]==0 && s[r] == s[i])
                {
                    vis[r]=1;
                    break;
                }
                
            }
            }
 
        }
        int cnt= 0 ;
        for(int i =  0;i<s.size();i++)
        {
            if(vis[i]==0)
                cnt++;
        }
        return cnt;
        
    }
};
//"kkkkqdxre"
//6
//ipi