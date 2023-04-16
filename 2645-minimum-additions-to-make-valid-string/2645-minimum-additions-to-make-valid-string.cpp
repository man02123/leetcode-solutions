class Solution {
public:
    int addMinimum(string w) {
        int n=w.size();
        int i=0,ans=0;
        while(i<n)
        {
            int cnt=0;
            if(w[i]=='a')
                cnt++,i++;
            if(i<n && w[i]=='b')
                cnt++,i++;
            if(i<n && w[i]=='c')
                cnt++,i++;
            ans+=3-cnt;
        }
        return ans;
        
        
    }
};