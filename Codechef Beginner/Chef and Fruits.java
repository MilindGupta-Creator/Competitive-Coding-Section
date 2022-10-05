
import java.util.*;
import java.lang.*;
import java.io.*;
import java.lang.Math.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int q=0;q<t;q++){
		    int n=sc.nextInt();
		    int m=sc.nextInt();
		    int k=sc.nextInt();
		    while(n!=m&&k>0){
		        if(n<m)
		            n++;
		        else
		            m++;
		            k--;
		        
		    }
		    System.out.println(Math.abs(n-m));
		}
	}
}
