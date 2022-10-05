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
		    String str=sc.next();
		    Stack<Character>st=new Stack<Character>();
		    for(int i=0;i<str.length();i++){
		        char ch=str.charAt(i);
		        if(ch=='(')
		            continue;
		        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
		            st.push(ch);
		        else if(ch == ')')
		            System.out.print(st.pop());
		        else
		            System.out.print(ch);
		    }
		    System.out.println();
		}
	}
}
