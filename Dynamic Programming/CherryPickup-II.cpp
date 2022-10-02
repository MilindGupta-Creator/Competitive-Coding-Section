//  Leetcode-Cherry Pickup II (3D DP)




/* Thought process : */

// greedy will work here ?
// No
// But Why Bro ?
// bcoz there is no uniformity in matrix , suppose considering the current situation , lets say you
// choose the path having current val as maximum but may in the future it is possible that in some other path
// there is/are greater values then that path can be the answer .
// thats why Greedy will not work.

// Greedy not working -> Try Out All Possible Paths -> Recursion

// this is a case of fixed starting point and variable ending point.

// Now one can say, lets first find the max cherries picked by robot1 by recursion and then similarly
// find the totalcherris picked up by robot2 and then add both and return the ans

// but in this case if u will observe , u can see there are possibilites that one or more than one cells
// can be common in both their paths and as we know A/q , cell in the path should be counted one time only.

// so again you have to traverse the grid and have to remove the common ones
// it will be quite tedious and as well as long . so We will not do that.

// so What we will do bro ?
// for both robots , we will traverse simulataneuously.

// Lets Get Started !

// step 1 ) express in terms of indexes
// f(i1,j1,i2,j2)
// but as we are traversing simultaneously , i1==i2
// therefore we will reduce it to f(i,j1,j2)

// now lets think about base cases , Think of base cases like (1) Destination Base Case , (2) Out Of Bound Case

// write out of bound case before destination case as it will ocurr before the last row .

// step 2 ) Explore all paths

// Think of any instant , you will see for each option of robot A , robot B has Three Options
// i.e total ways = 3 *3 = 9 ways . so we will try out all those rest will be done by recursion
// also remember the consider the cases of being in the same cell and different cell

// step 3 ) return the maximum

////////////////////////////////////////////////////////

// as we know recursion gives exponential time complexity so we will have to reduce it

// so if there are overlapping subproblems we can apply memoization

// for that lets think of the dp array , think about its size
// for its size think about possibles values of parameters present in your dp (in our case f(i,j1,j2))
// possible values of i -> 0 to n-1 i.e N values , j1 -> 0 to m-1 i.e M values , j2 -> 0 to m-1 i.e M values.

// so our array will be : dp[N][M][M] of NMM

// res u Know what to do .

// memoization : TC : O(NMM)9
// SC : O(NM*M)(dp array) + O(N)(stack space)





class Solution {
public:
int MaxCherry(int i,int j1, int j2 ,int n,int m, vector<vector>& grid, vector<vector<vector>> &dp) {

     // base case
     if(j1<0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8 ;
     
     if(i==n-1)
     {
         
         if(j1==j2) return grid[i][j1] ;
         else return grid[i][j1] + grid[i][j2] ;
     }
      if(dp[i][j1][j2] != -1) return dp[i][j1][j2]  ;
     
     // Try Out All Possible Paths
      int maxi = INT_MIN ;
     
     for(int dj1 = -1 ;dj1 <= 1 ;dj1++) {
           for(int dj2 = -1 ;dj2 <= 1 ;dj2++) {
                
              int sum  = 0 ;
              
               // both robot are in same cell
              if(j1==j2)  sum += grid[i][j1] ;
               
               // both are in different cell
              else sum += grid[i][j1] + grid[i][j2]  ;
               
              sum += MaxCherry(i+1,j1+dj1,j2+dj2,n,m,grid,dp) ;
               
              maxi = max(maxi,sum) ;
           }
     }
     
     // return the maximum
     return dp[i][j1][j2] =  maxi ;
     
     
 }


int cherryPickup(vector<vector<int>>& grid) {
    
    int n = grid.size() ;
    int m = grid[0].size() ;
    vector< vector< vector<int> > > dp(n , vector< vector<int> > (m, vector<int> (m,-1) ) );
    return MaxCherry(0,0,m-1,n,m,grid,dp) ;
    
}
};
