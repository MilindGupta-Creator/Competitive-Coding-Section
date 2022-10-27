
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
		    int x=sc.nextInt();
		    int y=sc.nextInt();
		    int p=x+y;
		    for(int i=p+1;i<=Integer.MAX_VALUE;i++){
		        int prime=1;
		        for(int j=2;j<i;j++){
		            if(i%j==0){
		                prime=0;
		                break;
		            }
		            
		        }
		        if(prime==1){
		            System.out.println(i-p);
		            break;
		        }
		    }
		}
	}
}
