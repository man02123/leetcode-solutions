#define ll long long 
class Solution {
public:
    long long totalCost(vector<int>& co, int k, int c) {
        priority_queue<ll,vector<ll>,greater<ll>> pq1,pq2;
        
        int i=0,j=co.size()-1;
        int n = co.size();
        ll res=0;
        
        while(k>0)
        {
            while(i<n && i<=j && pq1.size()<c)
                pq1.push(co[i++]);
            
            while(j>=0 && j>=i && pq2.size()<c)
                pq2.push(co[j--]);
            
            ll c1 =INT_MAX,c2=INT_MAX;
            
            if(pq1.size()>0)
            {
                c1=pq1.top();
            }
            if(pq2.size()>0)
            {
                c2=pq2.top();
            }
            
            if(c1<=c2)   //breaking the tie on the basis of index 
            {
                res+=c1;
                pq1.pop();
            }
            else
            {
              res+=c2;
                pq2.pop();
            }
            k--;
        }
        
     return res;   
    }
};