import java.io.*;
import java.math.*;
import java.util.*;
public class Main{
	public static void main(String[] args){
        BigInteger n;
        int a, b;
     	Scanner cin = new Scanner(System.in);
        a = cin.nextInt();
        b = cin.nextInt();
        //System.out.println(a);
        //System.out.println(b);
        BigInteger r = BigInteger.valueOf(a);
        //System.out.println(r);
        BigInteger l = BigInteger.valueOf(b);
        r = r.pow(b);
        l = l.pow(a);
        r = r.subtract(l);
        System.out.println(r);
	}
}
