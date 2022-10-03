class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dp) {
      int n = dp.size();
    int m = dp[0].size();
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(i == n-1 && j == m-1) {
                dp[i][j] = min(0,dp[i][j]);
            }
            else if(i == n-1) 
                dp[i][j] = min(0,dp[i][j+1] + dp[i][j]);
            
            else if(j == m-1) 
                dp[i][j] = min(0,dp[i+1][j] + dp[i][j]);
            
            else 
                dp[i][j] = min(0,dp[i][j] + max(dp[i][j+1], dp[i+1][j]));
        }
    }
    return abs(dp[0][0]) + 1;
        
    }
};