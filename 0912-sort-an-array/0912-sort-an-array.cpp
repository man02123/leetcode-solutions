class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
//         vector<int> res(nums.size(),0);
//         msort(nums,0,nums.size()-1,res);
//     }
//     void msort(vector<int>& nums,int l,int h,vector<int> &res)
//     {
//        if(l>=h)
//            return;
        
//              int mid=(l+h)/2;
//             msort(nums,l,mid,res);
//             msort(nums,mid+1,h,res);
//             merge(nums,l,mid,h,res);
           
//     }
//     void merge(vector<int>& nums,int l,int mid,int h,vector<int> &res)
//     {
//         vector<int> temp;
        
//         int b=mid;
//         int last=h-mid;
        
//     }
        sort(nums.begin(),nums.end());
            return nums;
    }
};