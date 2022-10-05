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
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int q=0;q<t;q++){
		    int n=sc.nextInt();
		    int k=sc.nextInt();
		    int max=0;
		    for(int i=1;i<=k;i++){
		        if((n%i)>max){
		            max=n%i;
		        }
		    }
		    System.out.println(max);
		}
	}
}
