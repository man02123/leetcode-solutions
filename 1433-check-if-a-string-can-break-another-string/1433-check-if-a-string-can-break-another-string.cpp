class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
      sort(s1.begin(),s1.end());
       sort(s2.begin(),s2.end());
        bool f1 =true,f2=true;
        
        for(int i = 0;i<s1.size();i++)
        {
            if(s1[i]>s2[i] )
                f2 = false;
            
            if(s1[i]<s2[i])
                f1 = false;
            
                
        }
        
        
        return f1||f2;
        //sort(s1.begin(),s1.begin());
        
        
    }
};