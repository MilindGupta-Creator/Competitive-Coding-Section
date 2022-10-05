//program to evaluate a prefix equation
import java.util.*;
class EvaluatePrefix {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String exp=in.nextLine();
        Stack<Integer> st=new Stack<>();
        for(int i=exp.length()-1;i>=0;i--){
            char c=exp.charAt(i);
            if(Character.isDigit(c)){
                st.push(c-'0');
            }
            else{
                int a=st.pop();
                int b=st.pop();
                switch (c) {
                    case '+':
                        st.push(a+b);
                        break;
                    case '-':
                    st.push(a-b);
                    break;
                    case '*':
                    st.push(a*b);
                    break;
                    case '/':
                    st.push(a/b);
                    case '^':
                    st.push((int)Math.pow(a, b));
                    break;
                    case '%':
                    st.push(a%b);
                }
            }
        }
        int result=st.pop();
        System.out.println(result);
        in.close();
    }    
}
