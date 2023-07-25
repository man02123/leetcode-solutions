class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        while(i<n && arr[i]<arr[i+1])
            i++;
        int res=i;
        while(i<n-1 && arr[i]>arr[i+1] )
         i++;
        
  if(i==(n-1))
      return res;
        else
            return -1;
        
        
    }
};