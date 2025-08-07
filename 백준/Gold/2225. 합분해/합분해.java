import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N,K;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input;
        input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);

        dp = new int[N+1][K+1];

        for(int i=1; i<=K; ++i){
            dp[0][i]=1;
        }
        for(int i=0; i<=N; ++i){
            dp[i][1]=1;
        }

        for(int i=1; i<=N; ++i){
            for(int j=2; j<=K; ++j){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j])%1_000_000_000;
            }
        }

        System.out.println(dp[N][K]);

    }


}
