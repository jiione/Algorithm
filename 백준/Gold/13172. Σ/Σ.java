import java.io.*;
import java.util.*;

public class Main {
    static final long MOD = 1_000_000_007L;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine().trim());

        long ans = 0;
        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long N = Long.parseLong(st.nextToken()); // 분모
            long S = Long.parseLong(st.nextToken()); // 분자

            N %= MOD;
            S %= MOD;

            long invN = modPow(N, MOD - 2); // N^(MOD-2) % MOD
            long term = (S * invN) % MOD;
            ans += term;
            if (ans >= MOD) ans -= MOD;
        }

        System.out.println(ans % MOD);
    }

    // 빠른 거듭제곱: a^e % MOD
    static long modPow(long a, long e) {
        long res = 1L;
        a %= MOD;
        while (e > 0) {
            if ((e & 1L) == 1L) res = (res * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return res;
    }
}
