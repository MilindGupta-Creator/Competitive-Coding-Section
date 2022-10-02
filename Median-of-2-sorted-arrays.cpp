// naive approach 1 : merge both the array and sort it and then u can easily canculate median
// TC : O(N+M)log(N+M) SC : O(N+M)

// Approach 2 : merge both array in sorted order using Two pointers and then we can get our answer
// TC : O(N+M) SC : O(N+M)

// Approach 3 : while merging both the array using 2 pointers , we can store middle and middle-1 element
// TC : O(N+M) SC : O(1)

// Approach 4 : We try to partition the arrays such that the left elements of median <= right elments of
// median
// Ex : {7,12,14,15} ,{1,2,3,4,9,11} -> [1,2,3,4,7 | 9,11,12,14,15]

// we do this by applying binary search on smaller array

// TC : O(log(min(n,m))) SC : O(1)

class Solution {
public:
double findMedianSortedArrays(vector& nums1, vector& nums2) {

    if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1) ;
    int n = nums1.size() ;
    int m = nums2.size() ;
    
    
// so i need to do partition so ,that means i need to pick some elements from num1 and rem from nums2.
    
int s = 0 ; // minimum elements i can pick from nums1(smaller array) || u can say minimum cut u can do.
int e = n ; // maximum elements i can pick from nums1 || maxmum cut u can do.
    
    while(s<=e) {
        
        int mid = s + (e-s)/2 ;
        
        int cut1 = mid ;
        int cut2 = (n+m+1)/2-cut1 ;
        
        int l1 = cut1==0 ? INT_MIN : nums1[cut1-1] ;
        int l2 = cut2==0 ? INT_MIN : nums2[cut2-1] ;
        
        int r1 = cut1==n ? INT_MAX : nums1[cut1] ;
        int r2 = cut2==m ? INT_MAX : nums2[cut2] ;
        
        // obv l1 < r1  and l2 < r2 so need to check it
        
        if(l1<=r2 and l2<=r1) {
            
            if((n+m)&1) return max(l1,l2) ;
            else {
                double ans = (max(l1,l2) + min(r1,r2))/2.0 ;
                return ans ;
            }
        }
        else if(l1 > r2) e = mid-1 ;
        else s = mid+1 ;
        
    }
    
    return 0.0 ;
    
    
    
}
};
