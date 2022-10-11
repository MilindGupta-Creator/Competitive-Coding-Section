// Steps of DP

// 1 ) Express your function in terms of index
// 2 ) Think of base case
// 3 ) Try out all possible stuff
// 4) return the min/max of all
// 5) Think of Out of Bound cases in Your code

/////////////////////////////////////////////////////////////////////

// Recursion : TC : O(2^N) SC : O(N)

// for memoization : TC : O(N) SC : O(N) + O(N)
// Observe the changing parameter
// here max size of idx is n so the dp size will n+1

////////////////////////////////////////////////////////////////////////

// Tabulation : TC : O(N) SC : O(N) (only dp space no stack space )
// 1 ) write base case
// 2 ) write for loop -> no of loop = no of changing parameters
// 3 ) copy paste recursive statements from memoization

/////////////////////////////////////////////////////////////////////

//Space Optimization : TC :O(N) SC :O(1)
// remember when ever there is things like idx-1 , idx-2... etc there will always be possibility of space optimization
// Think from bottom to top i.e tabulation wise.

////////////////////////////////////////////////////////////////////

class Solution {
public:

int helper(int idx , vector<int>&nums , vector<int>&dp) {
    
   
    if(idx == 0)
        return nums[0] ;
    
    if(dp[idx] != -1)
        return dp[idx] ;
    
    int pick = nums[idx] ;
    if(idx-2 >=0)
        pick += helper(idx-2,nums,dp) ;
    else 
        pick += 0 ;
    
    
    int notPick = helper(idx-1,nums,dp) ;
    

    return dp[idx] = max(pick , notPick) ;
    
   
}

int rob(vector<int>& nums) {
    
int n = nums.size() ;
// vector<int>dp(n+1,0) ;
// return helper(n-1,nums,dp) ;
    
// dp[0] = nums[0] ;
int prev = nums[0] ;
int prev2 =nums[0] ;
for(int idx = 1 ;idx < n ; idx++) {
    
    int pick = nums[idx] ;
    if(idx-2 >=0)
        pick += prev2 ;
    else 
        pick += 0 ;
    
    
    int notPick = prev ;
    

   int curr = max(pick , notPick) ;
   prev2 = prev ;
   prev = curr ;
}
    
return prev ;


    
    
}
};
