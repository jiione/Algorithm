import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int [] dp = new int[11];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for(int i=4; i<=10; ++i){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for(int i=0; i<n; i++){
            int t = Integer.parseInt(br.readLine());
            sb.append(dp[t]).append("\n");
        }
        System.out.println(sb);
    }
}
