// The happy number can be defined as a number which will yield 1 when it is replaced by the sum of the square of its digits repeatedly
//Approach 1:
//Runtime: 2ms
//Memory usage: 33MB
import java.util.*;
class Solution {
    
    //Using HashMaps to store the evaluated values to detect repetitions.
    
    //FUNC TO RETURN WHETHER NUMBER IS HAPPY OR NOT
    public static boolean isHappy(int n) {
        HashSet<Integer> set = new HashSet();
        set.add(n);
        int sum = n;
        while(sum!=1){
            sum = getDigitSqrSum(sum);
            if(set.contains(sum)){
                return false;
            } else {
                set.add(sum);
            }
        }
        return true;
    }
    //FUNCTION TO ADD SQUARE OF EACH DIGIT OF THE NUMBER
    
    private static int getDigitSqrSum(int n){
        int sum = 0;
        while(n!=0){
            int d = n%10;
            sum+=(d*d);
            n=n/10;
        }
        return sum;
    }
    public static void main(String[] arg){
        int number = 19;
        System.out.println(isHappy(number));
    }
}
