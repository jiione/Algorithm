import java.io.*;
import java.util.*;

class Edge {
    int to;
    int w;
    Edge(int to, int w) { this.to = to; this.w = w; }
}

class Node implements Comparable<Node> {
    int v;
    int dist;
    Node(int v, int dist) { this.v = v; this.dist = dist; }
    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.dist, o.dist); // 최소 힙
    }
}

public class Main {
    static List<Edge>[] graph;
    static int[] dist;
    static int[] parent;
    static final int INF = Integer.MAX_VALUE / 4;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()); 
        int m = Integer.parseInt(br.readLine()); 

        graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) graph[i] = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph[u].add(new Edge(v, w)); 
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        dist = new int[n + 1];
        parent = new int[n + 1];
        Arrays.fill(dist, INF);
        Arrays.fill(parent, -1);

        dijkstra(start);

        
        List<Integer> path = new ArrayList<>();
        for (int cur = end; cur != -1; cur = parent[cur]) path.add(cur);
        Collections.reverse(path);

        StringBuilder out = new StringBuilder();
        out.append(dist[end]).append('\n');        
        out.append(path.size()).append('\n');      
        for (int i = 0; i < path.size(); i++) {
            if (i > 0) out.append(' ');
            out.append(path.get(i));
        }
        System.out.println(out);
    }

    static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        dist[start] = 0;
        parent[start] = -1;
        pq.offer(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            int u = cur.v;
            int d = cur.dist;

            
            if (d != dist[u]) continue;

            for (Edge e : graph[u]) {
                int v = e.to;
                int nd = d + e.w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    parent[v] = u;        
                    pq.offer(new Node(v, nd));
                }
            }
        }
    }
}
