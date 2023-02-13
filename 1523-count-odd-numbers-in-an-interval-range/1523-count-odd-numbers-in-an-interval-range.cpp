class Solution {
public:
    int countOdds(int l, int h) {
        int res=0;
        int range=h-l+1;
        if(l%2==1 && h%2==1)
            return range/2+1;
        return range/2;
    }
};