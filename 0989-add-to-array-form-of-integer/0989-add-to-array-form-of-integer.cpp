class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        vector<int> res;
        int carry=0;
        
        while(k!=0 || i>=0)
        {
            int tempsum=carry;
            
            if(k!=0)
            {
               tempsum+=k%10;
                k=k/10;
            }
            if(i>=0)
                tempsum+=num[i--];
            
            if(tempsum>=10)
                res.emplace_back(tempsum-10),carry=1;
            else
                res.emplace_back(tempsum),carry=0;
            
        }
        if(carry>0)
            res.emplace_back(carry);
        reverse(res.begin(),res.end());
        return res;
        
    }
};