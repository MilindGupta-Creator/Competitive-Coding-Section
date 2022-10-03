
class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        int i, total;
        total = (n) * (n+1 ) / 2;
        for (i = 0; i < n-1; i++)
        {
            total -= array[i];
        }
        return total;
        
    }
};
