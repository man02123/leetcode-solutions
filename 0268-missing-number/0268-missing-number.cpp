class Solution {
public:
    int missingNumber(vector<int>& a) {
         int i=0;
        int n=a.size();
   while(i<n) 
   {
       while(a[i]<n && a[i]!=i)
           swap(a[i],a[a[i]]);
       i++;
   }
   for(i=0;i<n;i++)
   {
       if(a[i]!=i)
       break;
   }
        return i;
        
    }
};