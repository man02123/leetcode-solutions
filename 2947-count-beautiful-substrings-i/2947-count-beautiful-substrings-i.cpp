class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        vector<int> pr = {0};
        int sum = 0;
        int ans = 0;
       for(int i =0;i<s.size();i++){
           if(isvol(s[i]))sum++;
           pr.push_back(sum);
       }
        
     
            
            for(int i =1;i<s.size();i++){
                for(int j =0;j<i;j++){
                    int len  = i-j+1;
                    int vol = pr[i+1]-pr[j];
                    int con = len-vol;
                    if(vol == con && (vol*con)%k == 0)ans++;
                   // if()
                }
            
                
        }
        return ans;
//       for(int i =2;i*i<=s.size();i++){
          
//           int len = i*i;
//           int cptr = 0;
//           for(int j=len-1;j<s.size();j++){
              
//               int vol= pr[j]-pr[cptr++];
              
//               int con = (len-vol);
//               if(vol == con && ((vol*con)%k == 0))ans++;
//           }
//       }
        return ans;
     }
    bool isvol (char x){
        if(x == 'a' || x=='e' || x =='o' || x=='i'|| x=='u')return true;
        return false;
    }
};