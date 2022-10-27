import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int q=0;q<t;q++){
		    int m=sc.nextInt();
		    int x=sc.nextInt();
		    int y=sc.nextInt();
		    int a[]=new int[m];
		    int h[]=new int[101];
		    for(int i=0;i<m;i++)
		    {
		        a[i]=sc.nextInt();  
		        int p=0,r=100;
		        p=a[i]-(x*y);
		        r=a[i]+(x*y);
		        if (p<1)
			        p=1;
			    if(r>100)
			        r=100;
		        for(int j=p;j<=r;j++)
		            if( h[j]==0 )
		                h[j]++;
		    }
		    int res=0;
		    for(int i=1;i<101;i++)
		    if(h[i]==0)
		    res++;
		    System.out.println(res);
		}
	}
}
