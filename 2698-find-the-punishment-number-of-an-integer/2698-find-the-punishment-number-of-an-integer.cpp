class Solution {
public:
    int punishmentNumber(int n) {
        
        int sum = 0;
        
        for(int i=1;i<=n;i++)
        {
            string s = to_string(i*i);
            
          if(check(i,s,0,0) == true)
          {
              
              sum+=i*i;
          }
        }
       // bool x = check(37,"1369",0,0,0);
      
        
        return sum;
        
    }
    bool check(int i,string s,int ind,int sum)
    {
        
        if(ind>=s.size())
            return sum == i;
        
     
        bool ans = false;
        for(int j = ind;j<s.size();j++)
        {

           ans = ans | check(i,s,j+1,sum+stoi(s.substr(ind,j-ind+1))); 
        }
        
        return ans;
        
    }
    
};