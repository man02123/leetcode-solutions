class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(auto it:arr)
            sum+=it;
        
        if(sum%3!=0)
            return false;
        int x=sum/3;
        
        int cnt=0;
        vector<int> pre;
        sum=0;
        bool zeroflag=false;
        
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==x)
            {
                sum=0;
                cnt++;
            }
            if(arr[i]!=0)
                zeroflag=true;
        }
        
        if(zeroflag==false && arr.size()>=3)
            return true;
       
        if(cnt>=3)
            return true;
        return false;
        
    }
};