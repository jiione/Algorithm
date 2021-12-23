import java.util.Scanner;

public class Algorithm {
    public static void main(String[] args) {
        long n,p,q;
        Scanner s = new Scanner(System.in);
        n=s.nextLong();
        p=s.nextLong();
        q=s.nextLong();
        long result=cal(n,p,q);
        System.out.println(result);
        return;
    }
    public static long cal(long n, long p, long q){
        if(n==0) return 1;
        return cal(n/p,p,q) + cal(n/q,p,q);
    }
}
