import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.Set;

public class Main {
    static int N;
    static int M;
    static int[] nums;
    static int[] board;
    static boolean[] visited;

    static Set<String> set = new LinkedHashSet<String>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        nums = new int[M];
        board = new int[N];

        input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            board[i] = Integer.parseInt(input[i]);
        }

        Arrays.sort(board);
        visited = new boolean[N];

        for(int i=0; i<N; ++i){
            visited[i] = true;
            nums[0] = board[i];
            dfs(1);
            visited[i] = false;
        }

        set.stream().forEach(System.out::println);
    }

    static void dfs(int len){
        if(len == M){
            StringBuilder sb = new StringBuilder();
            for(int i=0; i<M; ++i){
                sb.append(nums[i]).append(" ");
            }
            set.add(sb.toString());
            return;
        }

        for(int i=0; i<N; ++i){
            if(!visited[i]){
                visited[i] = true;
                nums[len] = board[i];
                dfs(len+1);
                visited[i] = false;
            }
        }
    }
}