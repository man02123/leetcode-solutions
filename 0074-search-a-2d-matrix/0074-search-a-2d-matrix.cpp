class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int tgt) {
        int low=0 ,high=matrix.size()-1;
         int n=matrix[0].size();
        int mid;
      while(low<=high)
        {
          mid=(low+high)/2;
          if(tgt<matrix[mid][0])
             high=mid-1;
          else if(tgt>matrix[mid][n-1])
            low=mid+1;
          else if(tgt>=matrix[mid][0] && tgt<=matrix[mid][n-1])
          break;
        }
        //cout<<mid; 
        int l1=0,r1=matrix[mid].size()-1;
        while(l1<=r1)
        {
            int mid1=(l1+r1)/2;
            //cout<<mid1;
            if(tgt==matrix[mid][mid1])return true;
            else if(tgt>matrix[mid][mid1])l1=(mid1+1);
            else if(tgt<matrix[mid][mid1])r1=mid1-1;
        }
     
       
        return false;
        
    }
};