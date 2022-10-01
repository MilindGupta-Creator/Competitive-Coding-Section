// one of the toughest but conceptual problem in dynamic programming

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = (int)slices.size() / 3;
        auto l1 = vector<int>(slices.begin(), slices.end()-1);
        auto l2 = vector<int>(slices.begin()+1, slices.end());
        return max(linear(l1, n), linear(l2, n));
    }
    
private:
    int linear(vector<int>& slices, int n) {
        vector<vector<int>> eat((int)slices.size()+2, vector<int>(n+1, INT_MIN));
        int res = INT_MIN;
        for (int i=0; i<eat.size(); ++i) eat[i][0] = 0;
        for (int i=2; i<eat.size(); ++i) {
            for (int j=1; j<n+1; ++j)
                eat[i][j] = max(eat[i-1][j], eat[i-2][j-1] + slices[i-2]);
            res = max(eat[i][n], res);
        }
        return res;
    }
};
