class Solution {
public:
    int dp[1005][1005];
    int fun(string& s, string& t, int i, int j)
    {
        if(j==t.size()) 
            return 1;
        if(i==s.size())
            return 0;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        if(s[i]==t[j])  
            return dp[i][j]=fun(s, t, i+1, j+1)+fun(s, t, i+1, j);
        else
            return dp[i][j]=fun(s, t, i+1, j);
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return fun(s, t, 0, 0);
    }
};