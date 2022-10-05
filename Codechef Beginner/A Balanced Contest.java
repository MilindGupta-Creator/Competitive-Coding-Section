
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int q=0;q<t;q++){
			int n=sc.nextInt();
			int p=sc.nextInt();
			int cakeWalk=0;
			int hard=0;
			int a[]=new int[n];
			for(int i=0;i<n;i++){
				a[i]=sc.nextInt();
			}
			for(int i=0;i<n;i++){
				if(a[i]>=p/2)
					cakeWalk++;
				else if(a[i]<=p/10)
					hard++;
			}
			if(cakeWalk==1&&hard==2)
				System.out.println("yes");
			else
				System.out.println("no");
		}
	}
}
