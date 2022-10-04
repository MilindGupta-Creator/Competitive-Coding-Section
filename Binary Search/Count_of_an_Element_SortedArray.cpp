/* 
Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. 
Expected time complexity is O(Logn) 
*/

/*
Approach:
This problem is same as finding first and last occurrences of x in sorted array.
It's just that they have framed the problem in a different way.
*/


/* 
Examples:
Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 1
  Output: 2 [1 occurs at index 0 and index 1 => 1-0+1 = 2]

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 4
  Output: -1 // 4 doesn't occur in arr[] 
*/


int binarySearch(vector<int>& nums, int target, bool flag)
    {
        int low = 0;
        int high = nums.size()-1;
        
        int ansIndex = -1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target)
            {
                ansIndex = mid;
                if(flag == 0)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return ansIndex;
    }


int countOccurrences(vector<int> arr, int target)
{
    int first = binarySearch(arr, target, 0);
    int last = binarySearch(arr, target, 1);
    
    if(first == -1 || last == -1)
        return -1;
    else
        return last - first + 1;

}
