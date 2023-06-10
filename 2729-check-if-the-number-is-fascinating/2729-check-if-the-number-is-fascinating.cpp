class Solution {
public:
    bool isFascinating(int n) {
        long long  x =2*n;
        long long y = 3*n;
        string a = to_string(x);
        string b = to_string(y);
        string c = to_string(n);
        
        string fin = c+a+b;
        
        sort(fin.begin(),fin.end());
        
        for(int i = 0;i<fin.size();i++)
        {
            if(fin[i]-'0' !=i+1)
                return false;
        }
        return true;
        
        
    }
};