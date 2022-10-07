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
		    String[] s = br.readLine().trim().split(" ");
			int n = Integer.parseInt(s[0]);
			int v1 = Integer.parseInt(s[1]);
			int v2 = Integer.parseInt(s[2]);
			
			if(v2>v1*Math.sqrt(2)) {
				System.out.println("Elevator");
			}else {
				System.out.println("Stairs");
			}
		}
	}
}
