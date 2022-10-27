import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		for(int i=0;i<t;i++)
		{
		    int n=s.nextInt();
		    int count=0;
		    int num=1;
		    while(n>0 && n>=num)
		    {
		        count++;
		        n=n-num;
		        num++;
		    }
		    System.out.println(count);
		   
		}
	}
}
