class Gcd {
    static int gcd(int n,int d){      //function to find gcd
        int remainder;
        while(n%d!=0){
            remainder=n%d;
            n=d;
            d=remainder;
        }
        return d;
    }

    static int lcm(int n,int d){     //function to find lcm
        return (n*d)/gcd(n,d);
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter two numbers ");
        int n=in.nextInt();int d=in.nextInt();
        if(gcd(n, d)==1){
            System.out.println("Numbers are coprime");
        }
        else{
            System.out.println("GCD of numbers is "+gcd(n,d)+" ,LCM of numbers is "+lcm(n,d));
        }
        in.close();
    }
}
