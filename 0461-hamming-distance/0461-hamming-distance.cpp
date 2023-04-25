class Solution {
public:
    int hammingDistance(int x, int y) {
       string a = bitset<32>(x).to_string();
        string b = bitset<32>(y).to_string();
        
        int res=0;
        for(int i=0;i<32;i++)
        {
            if(a[i]!=b[i])
                res++;
        }
      
        return res;
    }
};