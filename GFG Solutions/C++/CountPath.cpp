// Count all possible paths from top left to bottom right
// Link for Question = https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1
// GFG POD Question solution in C++

#define mod 1000000007

class Solution {

  public:

  int dp[101][101];

     int recursion(int n,int r){

         if(r==0 || n==0){

             return 1;

         }

         if(n<0 || r<0){

             return 0;

         }

         if(dp[n][r]!=-1){

             return dp[n][r];

         }

         int ch1 = recursion(n-1,r);

         int ch2 = recursion(n,r-1);

         return dp[n][r]=(ch1+ch2)%mod;

     }

    long long int numberOfPaths(int m, int n){

        // code here

        for(int i =0;i<101;i++){

            for(int j =0;j<101;j++){

                dp[i][j]=-1;

            }

        }

        long long int ans =  recursion(m-1,n-1);

        return ans;

    }

};

