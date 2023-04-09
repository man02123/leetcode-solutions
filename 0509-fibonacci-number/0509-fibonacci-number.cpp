class Solution {
public:
    int fib(int n) {
        if(n<2)
            return n;
        int res=0;
        
        int lst=1;
        int seclst=0;
        for(int i=2;i<=n;i++)
        {
            res=lst+seclst;
            seclst=lst;
            lst=res;
        }
        return res;
    }
};