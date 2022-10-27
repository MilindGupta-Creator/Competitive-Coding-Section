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
		        int count=0;
		        while(n!=0){
		            int x=(int)Math.sqrt(n);
		            count++;
		            n=n-x*x;
		        }
		        System.out.println(count);
		    }
	}
}
