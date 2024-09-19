import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        int[][] arr = new int[N][3];

        for(int i = 0; i < N; i++){
            arr[i]=Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        int[] dp =new int[D+1];

        for(int i=1; i<=D; ++i) dp[i] = i;

        for(int i=1; i<=D; i++){
            dp[i] = Math.min(dp[i], dp[i-1] +1);
            for(int j =0; j<N; ++j){
                if(arr[j][1] == i){
                    dp[i] = Math.min(dp[i], dp[arr[j][0]] + arr[j][2]);
                }
            }
        }
        System.out.println(dp[D]);

    }
}
