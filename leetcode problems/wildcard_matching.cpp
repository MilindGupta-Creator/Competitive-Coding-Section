class Solution {
public:
    bool solve(string &s1, string &s2 ,int i,int j,vector<vector<int>>&dp){
        // base condition
        if(i<0)return j<0;
        if(j<0){
            for(int idx=0;idx<=i;idx++){
                if(s1[idx]!='*')return 0;
            }
            return true;
        } 
        //check the cache
        if(dp[i][j]!=-1)return dp[i][j];
        //match
        if(s1[i]==s2[j] ||  s1[i]=='?')
            return  dp[i][j]=solve(s1,s2,i-1,j-1,dp);
        // if s1[i] is "*". we can '*' use any number of times ( 0 or more)
         if(s1[i]=='*')
             return  dp[i][j]=solve(s1,s2,i-1,j,dp) || solve(s1,s2,i,j-1,dp);
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        int m=p.size();
        int n=s.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(p,s,m,n,dp);
    }
};
