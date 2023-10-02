class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {
        
        int ans = INT_MAX;
        int l = 1,r = *max_element(bd.begin() , bd.end());
        
        while(l<=r){
            int mid = (l+r)/2;
                    
            if(pred(mid,bd,m,k) == true){
                ans = mid;
                r = mid-1;
            }
            else
              l = mid+1;          
        }
        return (ans==INT_MAX)?-1:ans;
        
    }
    bool pred(int mid ,vector<int>& bd , int m , int k ){
        
        int currbuq = 0;
        
        int i = 0 , n = bd.size();
        
        for(int i = 0;i<n;i++){
            
            if(bd[i] <= mid){
                int cstr = 1;
                int j = i+1;
                
                while(j<n && cstr<k && bd[j]<=mid){
                    cstr++;
                    j++;
                }
                
                i = j-1;
                if(cstr == k)
                    currbuq++;
            }
            
        }
        
        if(currbuq >= m)return true;
        return false;
       
    }
};