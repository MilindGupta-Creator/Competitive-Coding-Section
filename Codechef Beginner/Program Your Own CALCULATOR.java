import java.io.*;

class codeChef {

public static void main (String[] args) throws java.lang.Exception
	{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n1= Integer.parseInt(br.readLine().trim());
		int n2= Integer.parseInt(br.readLine().trim());
		char ch= (char) br.read();
		double ans=0;
		switch(ch){
		     case '+':
		          ans=n1+n2;
		          break;
		    case '-':
		         ans=n1-n2;
		         break;
		   case '*':
		          ans=n1*n2;
		          break;
		    case '/':
		         ans=n1*1.0/n2;
		}
		System.out.println(ans);
	}
    
}
