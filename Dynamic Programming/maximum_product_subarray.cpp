class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minm=nums[0],maxm=nums[0],n=nums.size(),maxp=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
                swap(minm,maxm);
            minm=min(nums[i],minm*nums[i]);
            maxm=max(nums[i],maxm*nums[i]);
            maxp=max(maxp,maxm);
        }
        return maxp;
    }
};