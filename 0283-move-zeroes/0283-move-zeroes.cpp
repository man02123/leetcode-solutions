class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=0;
	    while(i<n)
	    {
	        if(arr[i]!=0)
	        {
	            i++;
	        }
	        else 
	        {
	            j=i+1;
	            while(j<n)
	            {
	                if(arr[j]==0)
	                j++;
	                else 
	                break;
	            }
	            if(j==n)
	            return;
	            
	        swap(arr[i],arr[j]);
	        }
	        
	    }
        
        
    }
};