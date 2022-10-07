/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception{
	
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
         
        if(n>=1&&n<=50)
            System.out.println(100);
        else if(n>=51&&n<=100)
            System.out.println(50);
        else
            System.out.println(0);
	}
}
