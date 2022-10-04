
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), ans = 0;
        vector<int> left(n);
        // left will store max left height till ith index
        left[0] = height[0];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], height[i]);
        // right will store max right height till ith index
        vector<int> right(n);
        right[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], height[i]);
        // calculating trapped water
        for (int i = 1; i < n - 1; i++)
            ans += min(left[i], right[i]) - height[i];

        return ans;
    }
};