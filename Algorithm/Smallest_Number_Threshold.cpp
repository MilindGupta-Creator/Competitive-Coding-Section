#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int sumafterdivision(vector<int>&arr,int n , int div)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i]/div;
            // for calling ceil add one more
            // 5/2 will give 2 but we want 3 so add one to it
            if(arr[i]%div!=0)
            {
                sum++;
            }
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& arr, int threshold) {
        
        /*
        
            we need to find smallest divisor such that sum of arr divided
            by divisor is just less than threshold
            => pattern to observe
            arr = [ 1 ,  2 , 5 , 9  ]
            the max elem of the arr which when divided gives= 1+1+1+1=4
            so 4 is surely one of the ans.
            and the min div can be one which when divided gives = 1+2+5+9=17
            which is actually sum of the array
            
            so our ans lies in b/w 1 to max elem of arr
            
            why binary search:
            when divided by 1 :     17
            when divided by 2 :     10    (1+1+3+5)
            when divided by 3 :     7      (1+1+2+3)
            .....
            when divided by 9 :     4     (1+1+1+1)
            
            we can see a pattern of monotonic decreasing function
            this type of question comes under binary search on answer
        
        
        */
        
        
        int low=1,high=*max_element(arr.begin(), arr.end());
        int ans=high;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            // mid is giving <=threshold
            // but we are looking for even smaller number , hence do
            // a search on the left
            if(sumafterdivision(arr,arr.size(),mid)<=threshold)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
        return ans;
    }
};
