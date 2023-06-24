class Solution {
public:
    int longestString(int x, int y, int z) { 
        int ans = min(x,y)*4;
        if(x!=y)
            ans+=2;//
        
        ans+=2*z;//
        
        return ans;//
        
    }
};