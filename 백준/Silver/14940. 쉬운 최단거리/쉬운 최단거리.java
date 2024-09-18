import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Point {
    public int x, y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    private final static int[] DX = {1, -1, 0, 0};
    private final static int[] DY = {0, 0, -1, 1};
    private static int n, m;
    private static boolean[][] isVisited;
    private static int[][] map;
    private static int[][] distance;
    
    public static void main(String[] args)throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder builder = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        boolean isStartChecked = false;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int startX=-1, startY=-1;
        map = new int[n][m];
        distance = new int[n][m];
        isVisited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            map[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            if (!isStartChecked)
                for (int j = 0; j < m; j++)
                    if (map[i][j] == 2) {
                        isStartChecked = true;
                        startX = i;
                        startY = j;
                        break;
                    }
        }

        bfs(startX,startY);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (!isVisited[i][j] && map[i][j] == 1)
                    builder.append(-1 + " ");
                else
                    builder.append(distance[i][j] + " ");
            builder.append("\n");
        }

        System.out.print(builder.toString());
    }

    private static void bfs(int x, int y) {
        Queue<Point> queue = new LinkedList<>();
        queue.add(new Point(x, y));
        isVisited[x][y] = true;

        while(!queue.isEmpty()) {
            Point cur = queue.poll();

            for (int i = 0; i < 4; i++) {
                int nextX = cur.x + DX[i];
                int nextY = cur.y + DY[i];

                if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue;
                if (map[nextX][nextY] == 0) continue;
                if (isVisited[nextX][nextY]) continue;

                queue.add(new Point(nextX, nextY));
                distance[nextX][nextY] = distance[cur.x][cur.y] + 1;
                isVisited[nextX][nextY] = true;
            }
        }
    }
}
