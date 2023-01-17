class Solution {
public:unordered_set<int> st;
   
    bool canCross(vector<int>& p) {
      map<pair<int,int>,bool> mp;
        for(int i=0;i<p.size();i++)
        {
             st.insert(p[i]);
        }
        if(p[1]!=1)return false;
        
        return help(p,1,1,mp);
    }
    bool help(vector<int>& p,int cord,int pjump,map<pair<int,int>,bool> &mp)
    {
        if(st.find(cord)==st.end())return mp[{cord,pjump}]=false;
        if(pjump==0)return false;
        
        if(cord>p.back())return  mp[{cord,pjump}]=false;
        if(cord==p.back())return  mp[{cord,pjump}]=true;
        
        if( mp.find({cord,pjump})!=mp.end())
        { 
            bool x=mp[{cord,pjump}];
            return x ;
        }
        
        
        bool same=help(p,cord+pjump,pjump,mp);
        bool one=help(p,cord+pjump+1,pjump+1,mp);
        bool minus=help(p,cord+pjump-1,pjump-1,mp); 
        
        return  mp[{cord,pjump}]=same||one||minus;
    }
};