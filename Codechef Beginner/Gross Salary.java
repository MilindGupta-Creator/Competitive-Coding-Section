/* package codechef; // don't place package name! */

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
		    int s=sc.nextInt();
		    double hra=0;
		    double da=0;
		    double ans=0;
		    if(s<1500){
		        hra=s*0.1;
		        da=s*0.9;
		        ans=s+hra+da;
		        System.out.println(ans);
		    }
		    else{
		       hra=500;
		       da=s*0.98;
		       ans=s+hra+da;
		       System.out.println(ans);
		    }
		}
	}
}
