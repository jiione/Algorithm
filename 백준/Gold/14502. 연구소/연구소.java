
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Node {
    int x,y;

    Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int ans = 0;
    static int N,M;
    static int[][] map;
    static boolean[][] visited;


    static int[] dx ={0,0,1,-1};
    static int[] dy ={1,-1,0,0};


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        map = new int[N][M];
        visited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(input[j]);
            }
        }

        dfs(0);

        System.out.println(ans);
    }

    static void dfs(int cnt){
        if(cnt == 3){
            bfs();
            return;
        }

        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(!visited[i][j]&&map[i][j]==0){
                    visited[i][j] = true;
                    map[i][j] = 1;
                    dfs(cnt+1);
                    map[i][j] = 0;
                    visited[i][j] = false;
                }
            }
        }
    }

    static void bfs(){
        Queue<Node> q = new LinkedList<>();
        boolean[][] visited2 = new boolean[N][M];


        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(map[i][j] == 2){
                    q.offer(new Node(j, i));
                }
            }
        }

        while(!q.isEmpty()){
            Node cur = q.poll();
            for(int i=0; i<4; ++i){
                int x = cur.x+dx[i];
                int y = cur.y+dy[i];

                if(y>=0 && y<N && x>=0 && x<M && !visited2[y][x] && map[y][x] == 0){
                    q.offer(new Node(x, y));
                    visited2[y][x] = true;
                }
            }
        }

        int cnt=0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(map[i][j] == 0 && !visited2[i][j]) cnt++;
            }
        }

        ans = Math.max(cnt, ans);

    }
}