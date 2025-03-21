import java.io.*;
import java.util.*;

class Node {
    int r, c, dist;
    Node(int r, int c, int dist) {
        this.r = r;
        this.c = c;
        this.dist = dist;
    }
}

public class Main {
    static int N, result = 0, size = 2, eatCount = 0;
    static int[][] map;
    // 상, 좌, 우, 하 순 (행: r, 열: c) → 행 우선, 그 후 열 우선
    static int[] dr = {-1, 0, 0, 1};
    static int[] dc = {0, -1, 1, 0};
    static int sharkR, sharkC;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        
        // 입력 (각 줄은 공백으로 구분된 숫자)
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 9) {  // 상어의 시작 위치
                    sharkR = i;
                    sharkC = j;
                    map[i][j] = 0;  // 상어가 있는 위치는 빈 칸으로 처리
                }
            }
        }
        
        while (true) {
            Node fish = bfs(sharkR, sharkC);
            if (fish == null) break;  // 먹을 수 있는 물고기가 없으면 종료
            result += fish.dist;
            sharkR = fish.r;
            sharkC = fish.c;
            eatCount++;
            if (eatCount == size) {
                size++;
                eatCount = 0;
            }
            map[sharkR][sharkC] = 0;  // 먹은 물고기는 제거
        }
        System.out.println(result);
    }
    
    // 시작 위치에서 먹을 수 있는 물고기 중 가장 가까우며, 
    // 거리가 같다면 행 번호, 열 번호 순으로 우선하는 물고기를 찾는 BFS
    static Node bfs(int startR, int startC) {
        boolean[][] visited = new boolean[N][N];
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(startR, startC, 0));
        visited[startR][startC] = true;
        
        int minDist = Integer.MAX_VALUE;
        ArrayList<Node> candidates = new ArrayList<>();
        
        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            // cur.dist가 이미 후보 최소 거리보다 크다면 더 이상 탐색할 필요 없음
            if (cur.dist > minDist) break;
            
            // 먹을 수 있는 물고기 조건: 물고기의 크기가 상어의 크기보다 작고 0이 아닌 경우
            if (map[cur.r][cur.c] != 0 && map[cur.r][cur.c] < size) {
                minDist = cur.dist;
                candidates.add(cur);
            }
            
            // 4방 탐색
            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];
                if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                if (visited[nr][nc]) continue;
                // 지나갈 수 있는 조건: 해당 칸의 물고기 크기가 상어 크기보다 작거나 같아야 함
                if (map[nr][nc] > size) continue;
                visited[nr][nc] = true;
                queue.offer(new Node(nr, nc, cur.dist + 1));
            }
        }
        
        if (candidates.isEmpty()) return null;
        // 우선순위: 가장 작은 행 번호, 그 후 가장 작은 열 번호
        candidates.sort((a, b) -> {
            if (a.r == b.r) return a.c - b.c;
            return a.r - b.r;
        });
        return candidates.get(0);
    }
}
