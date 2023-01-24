class Solution {
public:
    int alternateDigitSum(int n) {
        string temp=to_string(n);
        int res=0;
       // bool flag=false;
        
        for(int i=0;i<temp.size();i++)
        {
            if((i)%2==0)
            {
                res+=(temp[i]-'0');
            }
            else
            {
                res-=(temp[i]-'0');
            }
        }
        return res;
        
    }
};