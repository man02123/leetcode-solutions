class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
      // int len = s.size();
        int l = 0;
        int cone = 0;
        int ans = s.size();
        for(int r =0;r<s.size();r++){
            if(s[r] == '1')cone++;
            if(cone == k)ans = min(ans,r-l+1);
            
            while(l < r && cone>=k ){
                if((s[l] == '1'))cone--;
                
                l++;
                if(cone == k)ans= min(ans,r-l+1);
            }
        }
        
        cone = 0;
       int lptr =0;
        
        while(lptr<ans)
        {if(s[lptr] == '1')cone++;lptr++;}
        
        string curr = "";
        
        if(k == cone)
        curr = s.substr(0,lptr);
        
         int left = 0;
        
        for(int i =lptr;i<s.size();i++){
            if(s[i] == '1')cone++;
            if(s[left++] == '1')cone--;
            
            if(cone == k && curr.size() == ans){
                curr = min(curr , s.substr(left,i-left+1));
            }
            else if(cone == k && curr.size() == 0)
                curr = s.substr(left,i-left+1);
            
            
        }
        

        return curr;
    }
};