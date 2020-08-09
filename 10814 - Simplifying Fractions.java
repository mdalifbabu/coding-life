import java.math.BigInteger;
import java.util.Scanner;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t > 0){
            //if(t == 0)break;
        	BigInteger a = sc.nextBigInteger();
        	char c = sc.next().charAt(0);
        	BigInteger b = sc.nextBigInteger();
        
        	BigInteger g = a.gcd(b);
        	System.out.println(a.divide(g) + "/" + b.divide(g));
        	t--;
        }
    }
}