class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        vector<int> lmin,rmin;
        
        stack<pair<int,int>> st;
        st.push({INT_MAX,-1});
        
        for(int i=0;i<h.size();i++)
        {
            while(st.size()>0 && st.top().first>=h[i])
                st.pop();
            
            if(st.size()==0)
                lmin.push_back(-1);
            else 
                lmin.push_back(st.top().second);
            
            st.push({h[i],i});
        }
        
        
        stack<pair<int,int>> st1;
        for(int i=h.size()-1;i>=0;i--)
        {
            while(st1.size()>0 && st1.top().first>=h[i])
                st1.pop();
            
            if(st1.size()==0)
                rmin.push_back(h.size());
            else 
                rmin.push_back(st1.top().second);
            
            st1.push({h[i],i});
        }
        reverse(rmin.begin(),rmin.end());
        // for(auto it:rmin)
        //     cout<<it;
        
        int res=0;
        for(auto i=0;i<h.size();i++)
        {
            int temp=(rmin[i]-lmin[i]-1)*h[i];
            res=max(res,temp);
        }
        
        
        
        return res;
    }
};