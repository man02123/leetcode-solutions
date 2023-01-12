class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        pair<double,pair<int,int>> p;
        priority_queue<pair<double,pair<int,int>>> pq;
        
        for(int i=0;i<arr.size()-1;i++)
            for(int j=i+1;j<arr.size();j++)
            {
                //cout<<arr[i]/arr[j]<<" ";
                p={(double)arr[i]/arr[j],{arr[i],arr[j]}};
                pq.push(p);
                if(pq.size()>k)
                    pq.pop();
            }
        
     return {pq.top().second.first,pq.top().second.second};  
    }
};