import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int[] board;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        String[] input;
        input=br.readLine().split(" ");
        board = new int[N+1];
        dp = new int[N+1][N+1];

        for(int i=1; i<=N; ++i){
            board[i] = Integer.parseInt(input[i-1]);
        }
        for(int i=1; i<=N; ++i){
            dp[i][i]=1;
        }

        for(int i=1; i<N; ++i){
            if(board[i]==board[i+1]) dp[i][i+1]=1;
        }

        for(int len=3; len<=N; ++len){
            for(int i=1; i+len-1 <= N; ++i){
                int j = i+len-1;

                if(board[i]==board[j] && dp[i+1][j-1]==1) dp[i][j]=1;
            }
        }

        int M = Integer.parseInt(br.readLine());
        StringBuilder answer = new StringBuilder();

        for(int i=0; i<M; ++i){
            input = br.readLine().split(" ");

            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);

            answer.append(dp[a][b]).append('\n');
        }

        System.out.println(answer.toString());

    }


}
