import java.io.*;

public class Main {
    static final long MOD = 1000000007;
    
    // fast doubling 알고리즘으로 피보나치 수를 구하는 함수
    // 반환값: [F(n), F(n+1)]
    static long[] fib(long n) {
        if(n == 0) return new long[]{0, 1};
        long[] half = fib(n / 2);
        long a = half[0];
        long b = half[1];
        // F(2k) = F(k) * [2*F(k+1) - F(k)]
        long c = (a * ((2 * b % MOD - a + MOD) % MOD)) % MOD;
        // F(2k+1) = F(k)^2 + F(k+1)^2
        long d = (a * a % MOD + b * b % MOD) % MOD;
        
        if(n % 2 == 0) {
            return new long[]{c, d};
        } else {
            return new long[]{d, (c + d) % MOD};
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine().trim());
        System.out.println(fib(n)[0]);
    }
}
