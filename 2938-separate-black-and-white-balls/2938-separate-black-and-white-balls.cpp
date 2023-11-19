class Solution {
public:
    long long minimumSteps(string s) {
     long long ans = 0;
       
        long long czero = 0;
        for(int i =s.size()-1;i>=0;i--){
            if(s[i] =='0')czero++;
            
            if(s[i] =='1')ans+=czero;
        }
        return ans;
    }
};