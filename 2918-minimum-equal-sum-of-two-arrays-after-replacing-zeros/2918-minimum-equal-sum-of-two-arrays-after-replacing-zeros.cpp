#define ll long long ;
class Solution {
public:
    long long minSum(vector<int>& n1, vector<int>& n2) {
       long long s1 = 0,s2=0;
       long long p1 = 0,p2=0;
    
        for(auto it:n1){
            if(it !=0)s1+=it;
            else
                p1++;
        }
        for(auto it:n2){
            if(it !=0)s2+=it;
            else
                p2++;
        }
        
        if(s1 == s2 && p1==p2)
            return s1+p1;
        if((p1 ==0) && (p2 ==0)){
            if(s1 != s2)
                return -1;
            else
                return s1;
        }
            
        
        if(s1 == s2){
            if(p1 == p2)
                return s1+p1;
            
            else if(p1 == 0 && p2!=0)
                return -1;
            else if(p1!=0 && p2 == 0)
                return -1;
            else{
                return s1+max(p1,p2);
            }
        }
        else{
            
            if(p1!=0 && p2!=0)
                return max(p1+s1,p2+s2);
            else if(p1 == 0){
                if(s2+p2 <= s1){
                    return s1;
                }
                else
                    return -1;
            }
            else
            {
               if(s1+p1 <= s2){
                    return s2;
                }
                else
                    return -1;  
            }
            
        }
        
        
        return -1;
    
    }
};