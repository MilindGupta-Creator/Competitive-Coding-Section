class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxm=0,minm=100000;
        for(int i=0;i<nums.size();i++)
        {
            maxm=max(maxm,nums[i]);
            minm=min(minm,nums[i]);
        }
        return __gcd(maxm,minm);
    }
};