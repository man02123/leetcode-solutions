class Solution {
public:
    int minOperations(string s) {
        int z =0,o =0;
        
        for(int i =1;i<s.size();i+=2){
            if(s[i]!='1')z++;
            
            if(s[i-1]!='0')z++;
        }
        if(s.size()%2 == 1){
            if(s.back()=='1')z++;
        }
        
         for(int i =1;i<s.size();i+=2){
            if(s[i]!='0')o++;
            
            if(s[i-1]!='1')o++;
        }
        if(s.size()%2 == 1){
            if(s.back()=='0')o++;
        }
        
        return min(o,z);
    }
};