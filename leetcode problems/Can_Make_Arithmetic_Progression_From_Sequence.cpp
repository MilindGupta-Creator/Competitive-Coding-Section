class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if (n == 0 or n == 1 or n == 2)
            return 1;
        int d = arr[0] - arr[1];
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] - arr[i + 1] != d)
                return 0;
        }
        return 1;
    }
};