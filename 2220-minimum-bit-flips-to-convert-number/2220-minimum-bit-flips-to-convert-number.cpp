class Solution {
public:
    int minBitFlips(int s, int g) {
        int x=s^g;
        int cnt=0;
        while(x>0)
        {
            if(x%2==1)
                cnt++;
            x=x/2;
        }
        return cnt;
        
    }
};