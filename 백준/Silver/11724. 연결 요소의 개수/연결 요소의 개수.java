import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);

        int[][] graph = new int[n+1][n+1];
        boolean[] visited = new boolean[n+1];

        Queue<Integer> q = new LinkedList<>();

        for(int i=1; i<=m; ++i){
            String[] line = br.readLine().split(" ");
            int u = Integer.parseInt(line[0]);
            int v = Integer.parseInt(line[1]);

            graph[u][v] = graph[v][u] = 1;
        }

        int result = 0;
        for(int i=1; i<=n; ++i){
            q.add(i);
            if(!visited[i]){
                result++;
                visited[i] = true;
            }

            while(!q.isEmpty()){
                int u = q.poll();
                for(int j=1; j<=n; ++j){
                    if(graph[u][j] == 1 && !visited[j]){
                        q.add(j);
                        visited[j] = true;
                    }
                }
            }
        }

        System.out.println(result);
    }
}
