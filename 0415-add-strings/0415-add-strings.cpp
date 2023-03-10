class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i=num1.size()-1;
        int j=num2.size()-1;
        string res;
        bool carry=0;
        
        while(i>=0 || j>=0)
        {
            int sum=carry;
            if(i>=0)
             sum+=num1[i--]-'0';
            if(j>=0)
                sum+=num2[j--]-'0';
                
            if(sum>=10)
                res+=to_string(sum-10),carry=1;
            else
              res+=to_string(sum),carry=0;       
        }
        if(carry>0)
            res+=to_string(carry);
        reverse(res.begin(),res.end());
        return res;
        
    }
};