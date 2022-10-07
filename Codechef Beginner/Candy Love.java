/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		while(T-->0){
		    
		    int N = Integer.parseInt(br.readLine().trim());
		    
		    String[] s = br.readLine().trim().split(" ");
		    
		    int sum =0;
		    
		    for(int i=0;i<s.length;i++){
		        
		        sum+=Integer.parseInt(s[i]);
		        
		    }int k = sum&1;
		    if(k>0)
		        System.out.println("YES");
		    else 
		        System.out.println("NO");
		}
		
	}
}
