/*
Given an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.

*/


class Solution {
public:
    int findMin(vector<int>& nums) {
       
        int low = 0, high = nums.size()-1;
        int n = nums.size();
        
        if(low == high)
            return nums[low];
        
        if(nums[low] < nums[high])
            return nums[low];
        
        while(low <= high)
        {
            int mid = low + (high-low);
            int prev = (mid-1+n)%n, next = (mid+1)%n;
            
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return nums[mid];
            else if(nums[mid] > nums[high])
                low = mid+1;
            else
                high = mid-1;
        }
        
        return -1;
    }
};