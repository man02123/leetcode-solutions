class Solution {
public:
    bool isPerfectSquare(int num) {
        int l =1, r= num;
        while(l<=r)
        {
            int mid = (l)+(r-l)/2;
            
            if((num%mid == 0) && mid == num/mid)
                return true;
            if(mid>num/mid)
                r = mid-1;
            else
                l =mid+1;
            
        }
        return false;
    }
};