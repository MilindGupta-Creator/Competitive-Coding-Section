/*
 *	https://www.codechef.com/problems/SNAKPROC
 */
import java.io.*;
import java.util.Stack;

class SNAKPROC {

	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine().trim());
		
		while(T-->0) {
			
			int n = Integer.parseInt(br.readLine().trim());
			
			String s = br.readLine().trim();
			
			String S ="";
			
			for(int i=0;i<s.length();i++) {
				
				if(s.charAt(i)=='H'|| s.charAt(i)=='T') 
				
					S += s.charAt(i);
			}
			if(S=="") {
				System.out.println("Valid");
				continue;
			}
			Stack<Character> sta = new Stack<>();
			
			for(int i=0;i<S.length();i++) {
				
				if(S.charAt(i)=='H') 
					if(sta.contains('H')&&!sta.isEmpty())
						break;
					else
						sta.push(S.charAt(i));
				else if(S.charAt(i)=='T'&&!sta.isEmpty()){
					
					if(sta.peek()=='H')
						
						sta.pop();
				}
				else{
					sta.push('I');
						break;
				}
						
			}
				
			
			
			if(sta.isEmpty())
				System.out.println("Valid");
			else 
				System.out.println("Invalid");
		}

	}

}
