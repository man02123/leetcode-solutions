class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int ans = 0;
        for(auto it:g)ans+=it.size();
     
        
        int mina = g.size(),minb=g.size(),minc = g.size();
        bool fa = false,fb =false,fc=false;
        for(int i =g.size()-1;i>=0;i--){
            string x = g[i];
            
            for(int j =0;j<x.size();j++){
                if(x[j] == 'P' && fa == false){
                    mina = i;
                    fa = true;
                }
            }
                
        }
         for(int i =g.size()-1;i>=0;i--){
            string x = g[i];
            for(int j =0;j<x.size();j++){
                if(x[j] == 'G' && fb == false){
                    minb = i;
                    fb = true;
                }
            }
            
                
        }
         for(int i =g.size()-1;i>=0;i--){
            string x = g[i];
            
            for(int j =0;j<x.size();j++){
                if(x[j] == 'M' && fc == false){
                    minc = i;
                    fc = true;
                }
            }
                
        }
        //cout<<mina<<minb<<minc;
         if(mina!=g.size())
        for(int i =0;i<mina;i++)ans+=t[i];
        
        if(minb!=g.size())
        for(int i =0;i<minb;i++)ans+=t[i];
        
        if(minc!=g.size())
        for(int i =0;i<minc;i++)ans+=t[i];
        return ans;
    }
};