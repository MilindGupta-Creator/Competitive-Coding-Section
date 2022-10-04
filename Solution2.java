// The happy number can be defined as a number which will yield 1 when it is replaced by the sum of the square of its digits repeatedly

//Approach 2:
//Runtime: 1ms
//Memory usage: 32.6MB 

import java.util.*;
class Solution2 {
   //Using Floyd Cycle detection algorithm

   //FUNC TO RETURN WHETHER NUMBER IS HAPPY OR NOT
    public static boolean isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while(slow != fast);
        if (slow == 1){
            return true;
        }
        else return false;
    }
    //FUNCTION TO ADD SQUARE OF EACH DIGIT OF THE NUMBER
    private static int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n>0) {
        tmp = n % 10;
        sum += tmp * tmp;   //ADDING SQUARE OF EACH DIGIT
        n /= 10;
    }
    return sum;
        
    }
    public static void main(String[] arg){
        int number = 19;
        System.out.println(isHappy(number));
    }
}