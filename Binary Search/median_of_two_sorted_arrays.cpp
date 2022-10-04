//Given two sorted arrays array1 and array2 of size m and n respectively. 
//Find the median of the two sorted arrays.

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums2.size()<nums1.size()) return MedianOfArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;
        
        while(low<=high){
            int cut1 = low+(high -low)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1==0? INT_MIN : nums1[cut1-1];
            int left2 = cut2 ==0? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1==n1?INT_MAX :nums1[cut1];
            int right2 = cut2 ==n2?INT_MAX:nums2[cut2];
            
            if(left1<=right2 &&left2 <=right1){
                if((n1+n2)%2 == 0)
                    return (max(left1, left2)+min(right1,right2))/2.0;
                else
                    return max(left1, left2);
            }else if(left1>right2){
                high = cut1-1;
            }else{
                low = cut1+1;
            }
            
        }
        return 0.0;
    
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


