class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        
        int count=0;
        int j=0;
        double avg=0;
        while(j<k)
            avg+=arr[j++];
        avg=avg/k;
        if(avg>=t)count++;
        
        for(int i=0;i+k<arr.size();i++)
        {
            avg=(avg*k-arr[i]+arr[i+k])/k;
            if(avg>=t)count++;
            
        }
        return count;    
        
    }
};