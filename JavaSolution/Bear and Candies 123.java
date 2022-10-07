/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-->0){
    		String s[] = br.readLine().trim().split("\\s+");
    	    
    	    int limak = Integer.parseInt(s[0]);
    		
    		int bob = Integer.parseInt(s[1]);
    		
    		int win = winner(limak,bob);
    		
    		if(win==1) System.out.println("Limak");
    		else System.out.println("Bob");
		}
	}
	
	static int winner(int limak, int bob){

	    int limakCandies = 0 , bobCandies = 0 ;

        for(int i=0;;i++) {
			
			if(i%2==1) {
				limakCandies += i;
				if(limakCandies > limak) {
					return 0;
				}
			}
			else {
				bobCandies += i;
				if(bobCandies > bob) {
					return 1;
				}
			}
	
        }
    }
}
