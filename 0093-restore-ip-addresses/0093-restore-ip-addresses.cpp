class Solution {
public:vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        string temp;
        
        if(s.size()>12)
            return res;
        
       bt(s,3,0,0,temp,false); 
        return res;
    }
    void bt (string &s, int dots,int ind,int seglen,string &temp,bool zero)
    {
        
        if(ind>s.size() || seglen>3 || dots<0)
            return;
        
        if(zero==true && seglen>1)
        {
            if((int)s[ind]>=0)
                return;
        }
        
        if(seglen==3)
        {
            string y;
            y=s.substr(ind-seglen,seglen);
            if(stoi(y)>255)
                return;
        }
        
        if(dots==0 && temp.size()==s.size()+3 && temp.back()!='.')
        {
            res.push_back(temp);
            return;
        }
        
        if(s.size()==0 || seglen==0)
        {
            temp.push_back(s[ind]);
            if(s[ind]=='0')
                zero=true;
            
            bt(s,dots,ind+1,seglen+1,temp,zero);
            temp.pop_back();
        }
        else
        {
            temp.push_back('.');
            bt(s,dots-1,ind,0,temp,false);
            temp.pop_back();
            
            temp.push_back(s[ind]);
            
            bt(s,dots,ind+1,seglen+1,temp,zero);
            temp.pop_back();
        }
        
        
        
        
    }
};