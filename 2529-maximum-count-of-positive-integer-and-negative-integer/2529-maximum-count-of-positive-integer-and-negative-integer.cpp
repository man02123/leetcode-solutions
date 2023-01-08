class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negcnt=0,poscnt=0;
       for(auto it:nums)
       {
           if(it==0)continue;
           if(it<0)negcnt++;
           else
               poscnt++;
       }
        int res=max(negcnt,poscnt);
        return res;
    }
};