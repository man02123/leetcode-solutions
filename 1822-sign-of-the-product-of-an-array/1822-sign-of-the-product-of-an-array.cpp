class Solution {
public:
    int arraySign(vector<int>& nums) {
        int  negcnt =0,zero=0;
        for(auto it:nums)
        {
            if(it<0)
                negcnt++;
            else if(it ==0)
                return 0;
        }
        if(negcnt%2 ==1)
            return -1;
        return 1;
    }
};