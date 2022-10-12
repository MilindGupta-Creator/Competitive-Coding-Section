class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int i=0,j=0;
        j=1;
        for(i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            else
                nums[j++]=nums[i];
        }
       return j;
    }
};