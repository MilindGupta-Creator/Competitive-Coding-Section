// 264. Ugly Number II : https://leetcode.com/problems/ugly-number-ii/





//  1)     Method 1 - By Dynamic Programming





//  Lets see what is a ugly number , 6 = 2*3  is a ugly number as it is a multiple of 2 and 3   but 7 is not a ugly number.
// Through this , we got to know that our ugly numbers will be multiples of 2 or multiples of 3
// or multiples of 5 . 

//  Now We Know we need to build our List of n ugly numbers , right ?
// our first number will be obviously 1 .

// Lets see for 2nd number , here contenders are : 2 , 3 , 5   ans = 2 ( as it is minimum)
// Now our contenders are : 4 , 3, 5   ans = 3 ( minimum one)
//         . 
// lets see for 6th number , here if  our contenders are :  6 , 6 , 10.  ans = 6 (minimum) .

// for 7th number  , contenders are : 12 , 6 , 10 .   hey but 6 has been done already , right ?
// so yes we will skip it , each time we will update our pointers.
   
// Similarly , we will keep on doing things , we will get 14 but this can't be our contender , right ?
// as it is not a ugly number. so we have to skip it somehow but how ?
// here dynamic programming comes into picture .  
// lets see  6 = 2*3 , 27 = 3*9 , 14 = 2*7 , 28 = 2 * 14 .
// So What You Observe ? 

// We Observed  each ugly number is a product of ugly numbers. That means I am 
// getting my current ugly number from our previously formed organised collections of ugly numbers. That what gave us Intuition of DP .i.e My answer is depending upon my previously solved answers.
// So we well never get 14 as our contender as 7 is not present in our list of Ugly Numbers. right ?

//        Things I need ?
//         1 ) Obviously  I need to use my previous ugly numbers. for  that I need to store them and hence I need dp array.

//         3) to get our multiples of 2 , 3  and 5 , I need to have 3 pointers. so that they can point   to previous ugly numbers.

//        4) Three variables to store multiple of 2 ,3 and 5.




//       Code : 

class Solution { {
public:

    int nthUglyNumber(int n) {
        
        vector<int>dp(n) ;
        
        dp[0] = 1 ;

        int pt1 = 0 ;
        int pt2 = 0 ;
        int pt3 = 0 ;
       
        for(int i=1 ;i<n ;i++) {
            
         
            int multipleof2 = dp[pt1] * 2 ;
            int multipleof3 = dp[pt2] * 3 ;
            int multipleof5 = dp[pt3] * 5 ;
            
            dp[i] = min({multipleof2 , multipleof3, multipleof5}) ;
            
            if(dp[i] == multipleof2) pt1++ ;
            if(dp[i] == multipleof3) pt2++ ;
            if(dp[i] == multipleof5) pt3++ ; 
         }
        return dp[n-1] ;
        
        
    }
};
