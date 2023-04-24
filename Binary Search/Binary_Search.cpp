/*
Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.
*/


int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        while(low<=high)
        {
            // same as mid = (low+high)/2, below one is to avoid overflow
            int mid = low+(high-low)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return -1;
    }
};