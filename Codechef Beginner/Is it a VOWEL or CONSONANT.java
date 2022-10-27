
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		String s1=sc.next();
		String s=s1.toLowerCase();
		for(int i=0;i<s.length();i++){
		    if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u'){
		        System.out.println("Vowel");
		    }
		    else{
		        System.out.println("Consonant");
		    }   
	    }
	}
}
