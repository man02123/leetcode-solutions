class Solution {
public:
    int countSymmetricIntegers(int l, int h) {
        
        int ans = 0;
        for(int i =l ;i<=h;i++ ){
            
            string s  = to_string(i);
            if(s.size() %2 !=0)
                continue;
            
            int csum = 0;
            int n =s.size();
            
            for(int j= 0;j<n/2;j++)
                csum += s[j]-'0';
            int rsum =0;
            
            for(int j = (n/2);j<s.size();j++)
                rsum += s[j]-'0';
            
            if(csum == rsum)
                ans++;
        }
        return ans;
        
    }
};