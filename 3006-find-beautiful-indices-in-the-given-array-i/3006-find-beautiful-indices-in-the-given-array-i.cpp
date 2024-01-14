class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ca1,ca2;
            
        for(int i =0;i<s.size();i++){
            
            if(s[i] == a[0]){
                int l = 0;
                //cout<<"err";
                for(int j = i;j<s.size();j++){
                    if(s[j] ==a[l]){
                        
                        l++;
                    }
                    else
                        break;
                }
                if(l == a.size())ca1.push_back(i);
                
            }
        }
            
            
            
            
          for(int i =0;i<s.size();i++){  
            
            if(s[i] == b[0]){
                int l = 0;
                for(int j = i;j<s.size();j++){
                    if(s[j] ==b[l]){
                        l++;
                    }
                    else
                        break;
                }
                
                if(l == b.size())ca2.push_back(i);
                
            }
          }
            
            vector<int> ans;
             if(ca2.size()>0)
            sort(ca2.begin() , ca2.end());
        
        //  for(auto it:ca1)cout<<it;
        // cout<<endl;
        //  for(auto it:ca2)cout<<it;
        // cout<<endl;
        
        
               if(ca2.size() == 0)
                   return {};
        
                for(int i=0;i<ca1.size();i++){
                   int num = ca1[i];
                    
                    int ind = lower_bound(begin(ca2), end(ca2),num-k)-begin(ca2);
                    //cout<<ind;
                    // if((ind ==0 && abs(ca2[ind] - num)<=k) || ()
                       //ans.push_back(num);
                    
                    int ind2 = upper_bound(begin(ca2), end(ca2),num+k)-begin(ca2);
                    
                    // if((ind2 ==ca2.size() && abs(ca2.back() - num)<=k)  || (ind2==0 && abs(ca2[ind2]-num) <=k))
                    if(ind>=0 && ind<ca2.size() && abs(ca2[ind]-num)<=k )
                       ans.push_back(num);
                     if(ind2>=0 && ind2<ca2.size() && abs(ca2[ind]-num)<=k )ans.push_back(num);
                }
        
          sort(begin(ans),end(ans));
        
          set<int> st = {begin(ans),end(ans)};
        return {begin(st),end((st))};
        return ans;
            
        }
};