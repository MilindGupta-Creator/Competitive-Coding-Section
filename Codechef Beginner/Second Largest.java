/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws IOException
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int q=0;q<t;q++){
		    int a[]=new int[3];
		    for(int i=0;i<3;i++){
                a[i]=sc.nextInt();
            }
            Arrays.sort(a);
            System.out.println(a[1]);
		}
	}
}
